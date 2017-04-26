function ploteazaEroareMisclasare(volum,eroareMisclasare,eroareTeoretica)

volum = log10(volum);

figure, hold on;
%plotam eroarea teoretica
semilogx(volum,eroareTeoretica*ones(1,length(volum)),'or');

%plotam eroarea empirica
semilogx(volum,eroareMisclasare,'xb');
title('Evolutia erorii de misclasare');
legend('eroarea teoretica','eroarea empirica');
%axis([min(volum) max(volum) 0 1]);
axis([min(volum) max(volum) min(eroareMisclasare)-0.05 max(eroareMisclasare)+0.05]);

