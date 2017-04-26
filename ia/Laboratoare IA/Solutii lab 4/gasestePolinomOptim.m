function P = gasestePolinomOptim(exempleAntrenare,gradPolinom)

x = exempleAntrenare(:,1);
u = exempleAntrenare(:,2);
P = polyfit(x,u,gradPolinom);