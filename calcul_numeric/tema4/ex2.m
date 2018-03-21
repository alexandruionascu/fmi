A = [
  1, -3, 3;
  3, -5, 3;
  6, -6, 4
];

% a
norm_A1 = sqrt(max(eigs(A' * A)));
% b
cond_A1 = norm_A1 * (1/sqrt(min(eigs(A' * A))));
% c
norm_A2 = norm(A, 2);
cond_A2 = cond(A, 2);