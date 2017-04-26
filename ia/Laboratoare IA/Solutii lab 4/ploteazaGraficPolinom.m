function ploteazaGraficPolinom(P)

x = 0:0.001:1;
predictii = polyval(P,x);
plot(x,predictii,'g');