c = 10;
volum = [10 10^2 10^3 10^4 10^5 10^6 10^7];
eroareMisclasare = zeros(1,length(volum));

for i = 1:length(volum)
    n = volum(i);
    %punctul a
    [X,Y] = genereazaMultimeAntrenare(n,c);
    %punctul b
    gstar = aplicaClasificatorBayesian(X,c);
    %punctul c
    eroareMisclasare(i) = calculeazaEroareMisclasare(Y,gstar);
end

%punctul d
eroareTeoretica = 0.305785;
ploteazaEroareMisclasare(volum,eroareMisclasare,eroareTeoretica);

%punctul e - pentru ale valori c se inlocuieste prima linie
%nu se va modifica graficul (asa iese si in teorie)

%punctul f - eroare empririca nu mai converge la eroarea teoretica
c = 10;
volum = [10 10^2 10^3 10^4 10^5 10^6 10^7];
p = 0.5;
for i = 1:length(volum)
    n = volum(i);
    %punctul a
    [X,Y] = genereazaMultimeAntrenare(n,c,'uniforma',p);
    %punctul b
    gstar = aplicaClasificatorBayesian(X,c);
    %punctul c
    eroareMisclasare(i) = calculeazaEroareMisclasare(Y,gstar);
end
eroareTeoretica = 0.305785;
ploteazaEroareMisclasare(volum,eroareMisclasare,eroareTeoretica);

%punctul g
p = 0.5;
for i = 1:length(volum)
    n = volum(i);
    %punctul a
    [X,Y] = genereazaMultimeAntrenare(n,c,'exponentiala',p);
    %punctul b
    gstar = aplicaClasificatorBayesian(X,c);
    %punctul c
    eroareMisclasare(i) = calculeazaEroareMisclasare(Y,gstar);
end
eroareTeoretica = 0.3015;%asta trebuie calculata
ploteazaEroareMisclasare(volum,eroareMisclasare,eroareTeoretica);
