function [X,Y] = genereazaMultimeAntrenare(n,c,optiuneRepartitie,p)

if nargin < 3
    optiuneRepartitie = 'uniforma';
end

switch optiuneRepartitie
    case 'uniforma'
        %X e repartizat uniform repartizat in [0,4c]
        X = rand(n,1) * 4*c;
    case 'exponentiala'
        %X e repartizat exponential de parametru lambda = c
        lambda = c;
        X = exprnd(lambda,n,1);
end

%eticheta lui Y
Y = rand(n,1) < (X./(X+c));

%generez etichetele Y ca realizari ale unei v.a Bernoulli(p)
if nargin >= 4
    Y = rand(n,1) < p;
end