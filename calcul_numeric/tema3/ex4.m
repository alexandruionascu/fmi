% exercitiul 1
A1 = [
  1, 2, 4;
  3, 8, 14;
  2, 6, 13
];
 
b = [
  1;
  1;
  0
];

[x,L,U] = desc_lu(A1,b);

% exercitiul 2
A2= [
  4, 2, 2;
  2, 10, 4;
  2, 4, 6
];

[x,L] = desc_cholesky(A2,b);

% exercitiul 3
A3 = [
  0, 4, 5;
  -1,-2,-3;
   0, 0, 1
];
[x,Q,R] = desc_qr(A3,b);