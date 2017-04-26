function E = calculeazaEroareMisclasare(Y,gstar)

E = mean(abs(Y-gstar));