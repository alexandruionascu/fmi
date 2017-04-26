function [X,T] = genereazaPuncteDeplasateFataDePrimaBisectoare(m,deplasare)

if nargin < 2
    deplasare = 0.3;
end

X = rand(2,m)*2-1;
T = (X(1,:) - X(2,:) < 0) * 2 -1;

figure, hold on;
eticheta1 = find(T==1);
etichetaMinus1 = find(T==-1);
X(2,eticheta1) = X(2,eticheta1) + deplasare;
X(2,etichetaMinus1) = X(2,etichetaMinus1) - deplasare;
plot(X(1,eticheta1),X(2,eticheta1),'or');
plot(X(1,etichetaMinus1),X(2,etichetaMinus1),'xg');
axis([-2 2 -2 2]);
