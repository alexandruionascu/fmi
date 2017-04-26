function eroare = calculeazaEroare(etichete,predictii)

eroare = mean((predictii-etichete).^2); 


