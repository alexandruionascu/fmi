function [wstar, bstar, eroareAntrenare] = algoritmRosenblattOnline(X,T,nrMaximEpoci)

if nargin < 3
    nrMaximEpoci = 100;
end

%initializare parametri hiperplan
w = zeros(size(X,1),1);
b = 0;

epocaCurenta = 1;
eroareAntrenare = ones(1,nrMaximEpoci);
nrExempleAntrenare = size(X,2);

while (epocaCurenta <= nrMaximEpoci)
   exempleMisclasate = 0;
   flag = true;
   for i=1:nrExempleAntrenare
       if (~isequal(hardlim(w'*X(:,i)+b),T(i)))
           exempleMisclasate = exempleMisclasate + 1;
           w = w+T(i)*X(:,i)
           b = b + T(i)
           flag = false;
       end
   end
   eroareAntrenare(epocaCurenta) = exempleMisclasate/nrExempleAntrenare; 
          
   if flag
       break;
   end
   disp(w);
   disp(b);
   epocaCurenta = epocaCurenta + 1;
end
wstar = w;
bstar = b;
eroareAntrenare(epocaCurenta+1:end) = [];