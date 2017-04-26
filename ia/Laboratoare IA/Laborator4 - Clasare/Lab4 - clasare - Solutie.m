rng default;% se initializeaza generatorul de nr pseudo-aleat 
            % pt a genera aceleeasi secvente de numere
%
% se intializeaza parametrii experimentului
%
p=0.25;                                      % prob. a-priorii a C_1
N=1000;                                      % vol total de selectie
mu0=[1,0]; mu1=[0,1];                        % vec. medie ai guassienelor
sig0=[1, -.4;-.4, .5]; sig1=[.5, .3;.3, .5]; % matr. de var-covar
%
% a) generarea supraf.&contur a Z0 & Z1, gauss. 2D cu param. de mai sus
%
x=-5:.2:5;
y=-5:.2:5;
[X,Y]=meshgrid(x,y);
Z0=mvnpdf([X(:) Y(:)],mu0,sig0);
Z0=reshape(Z0,length(y),length(x));
IZ0 = trapz(x,trapz(y,Z0,2)); % verific ca-i pdf
%
Z1=mvnpdf([X(:) Y(:)],mu1,sig1);
Z1=reshape(Z1,length(y),length(x));
IZ1 = trapz(x,trapz(y,Z1,2)); % verific ca-i pdf
%
figure, hold on
axis([-5.1 5.1 -5.1 5.1 0 1])
xlabel('x1'); ylabel('x2'); zlabel('Probability Density');
title('Probability Density of Z0 and Z1')
surfc(X,Y,Z0) 
surfc(X,Y,Z1) 
%
% b)genereaza supraf.&contur a lui Z mixtura de guassiene de mai sus
%
figure
Z=(1-p)*Z0+p*Z1;
IZ = trapz(x,trapz(y,Z,2)); % verific ca-i pdf
axis([-5.1 5.1 -5.1 5.1 0 1])
xlabel('x1'); ylabel('x2'); zlabel('Probability Density');
title('Probability Density of Z')
surfc(X,Y,Z)
%
% c) calculeaza eta(x), L_star si ploteaza eta(x)=0
%
Z3=min(p*Z1,(1-p)*Z0); % calculez eta(x)
L_star = trapz(x,trapz(y,Z3,2)); % calculez L_star
eta=p*Z1-(1-p)*Z0;
contour(X,Y,eta,[0 0],'ShowText','on') % plotez eta(x)=0
%
% d) genereaza si ploteaza vol. de selectie N
%
N1=round(p*N); N0=N-N1;
X0=mvnrnd(mu0,sig0,N0); y0=zeros(N0,1);
X1=mvnrnd(mu1,sig1,N1); y1=ones(N1,1);
figure, hold on
plot(X0(:,1),X0(:,2),'go',X1(:,1),X1(:,2),'ro')
%
% e) folosind modelul de discriminare liniara estimeaza dreapta de
%    discriminare. Ploteaza, in aceeasi fig., vol de selectie, dreapta de
%    regresie si eta
%
XR=[X0;X1];YR=[y0;y1];
LDiscr=fitcdiscr(XR,YR); % estimeaza functia de discriminare liniara
LDcoeff=struct2cell(LDiscr.Coeffs(1,2));
g_LD=[X(:),Y(:)]*LDcoeff{3,1}+LDcoeff{2,1};
g_LD=reshape(g_LD,length(y),length(x));
title('Theoret. Bayes and estim. Linear Discrim decisions curves')
contour(X,Y,g_LD,[0 0],'ShowText','on') % culoare si grosime diferita de eta
contour(X,Y,eta,[0 0],'ShowText','on')
%
% f) calculeaza matricea de confuzie si curba ROC a modelului de discrim.
%    liniara
%
[labelLD,PosteriorLD,CostLD] = predict(LDiscr,XR);
% Matricea de confuzie
figure
plotconfusion(YR',labelLD','Regression')
[cR,cmR,indR,perR] = confusion(YR',labelLD');
% Curba ROC
figure
plotroc(YR',labelLD')
title('Regression ROC Curve')
[tprR,fprR,thresholdsR] = roc(YR',labelLD');
%
% g) folosind modelul Naive Bayes calculeaza matricea de confuzie si curba
%    ROC
%
NBDiscr=fitcnb(XR,YR); % estimeaza Naive Bayes
[labelNB,PosteriorNB,CostND]=predict(NBDiscr,XR);
% Matricea de confuzie
figure
plotconfusion(YR',labelNB','Bayes')
[cB,cmB,indB,perB] = confusion(YR',labelNB');
% Curba ROC
figure
plotroc(YR',labelNB')
title('Bayes ROC Curve')
[tprB,fprB,thresholdsB] = roc(YR',labelNB');
%
hold off
% 
% Pt o prob. apriori data, se ploteaza in aceeasi fig. L_star, cB, cR
% (erorile de misclasare a lui NB, LD) pe axa Oy pt N=100; 200; 1000; 2000;
% 10000 pe axa Ox
%
% Se repeta graficul pt prob.ap.= 0.25; 0.5; 0.75