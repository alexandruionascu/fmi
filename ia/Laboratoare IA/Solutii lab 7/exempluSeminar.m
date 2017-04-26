%generare puncte din dintr-o distributie normala multidimensionala N(mu,Sigma) 
mu = [0 0];
Sigma = [.25 .35; .35 1];
nrPuncte = 20000;
r = mvnrnd(mu, Sigma, nrPuncte);
%ploteaza punctele
figure,
plot(r(:,1),r(:,2),'.');
axis([-5 5 -5 5]);

%ploteaza densitatea distributiei normale multidimensionale N(mu,Sigma)
x1 = -3:.2:3; x2 = -3:.2:3;
[X1,X2] = meshgrid(x1,x2);
F = mvnpdf([X1(:) X2(:)],mu,Sigma);
F = reshape(F,length(x2),length(x1));
figure
surf(x1,x2,F);
caxis([min(F(:))-.5*range(F(:)),max(F(:))]);
axis([-3 3 -3 3 0 .4])
xlabel('x1'); ylabel('x2'); zlabel('Probability Density');