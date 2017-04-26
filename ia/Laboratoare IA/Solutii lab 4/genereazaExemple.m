function exemple = genereazaExemple(nrExemple,sigmaZgomot,f) 

x = sort(rand(nrExemple,1),'ascend');
zgomot = randn(nrExemple,1)*sigmaZgomot;
exemple = [x f(x)+zgomot];