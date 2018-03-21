A = [ 
  10 7 8 7;
  7 5  6 5;
  8 6 10 9;
  7 5 9 10;
];
b = [
 32;
 23;
 33;
 31
];

% ex. a
x = inv(A) * b;

% ex. b
A2 = [
 10.00 7.00 8.10 7.20;
  7.08 5.04 6.00 5.00;
  8.00 5.98 9.89 9.00;
  6.99 4.99 9.00 9.98
];   
b2 = [ 
  32.1;
  22.9;
  33.1;
  30.9
];
x2 = inv(A2) * b2;
% Observatie: daca K creste => pentru perturbari mici in input apar perturbari mari
% in output 

%c
cond_1 = cond(A, 1);
cond_2 = cond(A, 2);
cond_inf = cond(A, Inf);