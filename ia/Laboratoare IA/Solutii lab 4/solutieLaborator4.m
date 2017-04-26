n = 10;
sigma = 0.25;

%punctul a + b
%genereaza exemple de antrenare
f = inline('sin(2*pi*x)','x');
S = genereazaExemple(n,sigma,f);
xS = S(:,1);
uS = S(:,2);

%punctul c
ploteazaExemple(S);
title('Exemple de antrenare');

gradPolinom = 0:1:9;
eroareS = zeros(1,length(gradPolinom));
eroareT = zeros(1,length(gradPolinom));

%genereaza exemple test
exempleT = genereazaExemple(n,sigma,f);
xT = exempleT(:,1);
uT = exempleT(:,2);

figure, hold on
for i =1:length(gradPolinom);
    
    %punctul d
    P = gasestePolinomOptim(S,gradPolinom(i));
    
    %punctul e + g
    subplot(4,3,i);hold on;
    ploteazaExemple(S);
    ploteazaGraficPolinom(P);
    legend('Exemple de antrenare', ['Solutia de grad ' num2str(gradPolinom(i))]);
    axis([0 1 -1.5 1.5]);
    
    %punctul f
    predictiiS = polyval(P,xS);
    eroareS(i) = calculeazaEroare(uS,predictiiS);
    
    pT = polyval(P,xT);
    eroareT(i) = calculeazaEroare(uT,pT);
end

%punctul h + i
figure, hold on
plot(gradPolinom, eroareS,'r');
plot(gradPolinom, eroareT,'b');
legend('eroarea pe exemplele de antrenare','eroarea pe exemplele de T');

%punctul j

gradPolinom = 0:1:6;
figure, hold on
indiciAleatori = randperm(size(S,1));
S1 = S(indiciAleatori(1:7),:);
S2 = S(indiciAleatori(8:end),:);

xS = S1(:,1);
uS = S1(:,2);
xT = S2(:,1);
uT = S2(:,2);

eroareS = zeros(1,length(gradPolinom));
eroareValidare = zeros(1,length(gradPolinom));
for i =1:length(gradPolinom);
    P = gasestePolinomOptim(S1,gradPolinom(i)); 
    subplot(4,3,i);hold on;
    ploteazaExemple(S1);
    ploteazaExemple(S2,'x','r');
    ploteazaGraficPolinom(P);
    legend('Exemple de antrenare','Exemple de test',...
        ['Solutia de grad ' num2str(gradPolinom(i))]);
    axis([0 1 -1.5 1.5]);
    
    pS = polyval(P,xS);
    eroareS(i) = calculeazaEroare(uS,pS);
    
    pT = polyval(P,xT);
    eroareValidare(i) = calculeazaEroare(uT,pT);
end

figure, hold on
plot(gradPolinom, eroareS,'r');
plot(gradPolinom, eroareValidare,'b');
legend('eroarea pe exemplele de antrenare S1','eroarea pe exemplele de validare S2');


gradOptim = gradPolinom(find(eroareValidare == min(eroareValidare)))

