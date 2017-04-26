%punctul b
X = [0 0 0 0.5 0.5 0.5 1 1;0 0.5 1 0 0.5 1 0 0.5];
T = [1 1 1 1 -1 -1 -1 -1];
figure, hold on;
eticheta1 = find(T==1);
etichetaMinus1 = find(T==-1);
plot(X(1,eticheta1),X(2,eticheta1),'or');
plot(X(1,etichetaMinus1),X(2,etichetaMinus1),'xg');
axis([-2 2 -2 2]);
[wstar, bstar, eroareAntrenare] = algoritmRosenblattOnline(X,T,500);
figure(gcf),plotpc(wstar',bstar);
title('Punctul a: plotare puncte + plotare dreapta de clasificare');
legend('puncte din clasa 1','puncte din clasa -1');
figure;
plot(eroareAntrenare);
legend('eroarea de antrenare');
title('Evolutia erorii de antrenare');

%punctul d
deplasare = [0.3 0.1 0.001 -0.1 -0.3];    
m =[10 50 100 250 500];

eroareAntrenare = cell(length(deplasare),length(m));

for i =1:length(deplasare)
    for j =1:length(m)
        [X,T] = genereazaPuncteDeplasateFataDePrimaBisectoare(m(j),deplasare(i));
        [wstar, bstar, E] = algoritmRosenblattOnline(X,T,500);
        eroareAntrenare{i,j} = E;
        figure(gcf),hold on,plotpc(wstar',bstar);
        title(['Dreapta de separare pentru nrExemple = ' num2str(m(j)) ' si deplasare = ' num2str(deplasare(i))]);
        legend('puncte din clasa -1','puncte din clasa 1','dreapta de separare');
        pause(3); close all;
        figure, hold on;
        plot(E);title(['Evolutia erorii de antrenare, cazul nrExemple = ' num2str(m(j)) ' si deplasare = ' num2str(deplasare(i))]);
        legend('eroarea de antrenare');
        pause(3);
    end
    
    nrEpoci = zeros(1,length(m));
    for j=1:length(m)
        nrEpoci(j) = length(eroareAntrenare{i,j});
    end
    
    figure,
    plot(m,nrEpoci);
    title(['Numarul de epoci necesare antrenarii pentru deplasare = ' num2str(deplasare(i))]);
    pause(3);
    
end