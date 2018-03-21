function [x] = GaussPivTot(A, b)
  n = size(A, 1);
  A = [A, b];
  xi = 1:n;
  for k = 1:(n - 1)
    p = k;
    m = k;
    for i = k : n
      for j = k : n
        if abs(A(i, j)) > abs(A(p, m))
          p = i;
          m = j;
        end
      end
    end
    
    if A(p, m) == 0
      disp('Sistem incompatibil sau sistem compatibil nedeterminat.');
      break;
    end
    
    if p != k
      A([p, k], :) = A([k, p], :);
    end
    
    if m != k
      A(:, [m, k]) = A(:, [k, m]);
      xi([m, k]) = xi([k, m]);
    end
    
    for l = k + 1 : n
      A(l, :) -= A(l, k) / A(k, k) * A(k, :);
    end
  end
  
  if A(n, n) == 0
    disp('Sistem incompatibil sau sistem compatibil nedeterminat.');
    break;
  end
  x_sd = SubsDesc(A(1: n, 1: n), A(:, n + 1));
  for i = 1: n
    x(xi(i)) = x_sd(i);
  end
end