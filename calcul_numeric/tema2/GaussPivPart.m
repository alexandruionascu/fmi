function [x] = GaussPivPart(A, b)
  A = [A, b];
  n = size(A, 1);
  for k = 1:n - 1
    p = k;
    for i = k : n
      if abs(A(i, k)) > abs(A(p, k));
        p = i;
      end
    end
    
    if A(p, k) == 0
      disp('Sistem incompatibil sau sistem compatibil nedeterminat.');
      break;
    end
    
    if p != k
      A([p, k], :) = A([k, p], :);
    end
    
    for l = k + 1 : n
      A(l, :) -= A(l, k) / A(k, k) * A(k, :);
    end
  end
  
  if A(n, n) == 0
    disp('Sistem incompatibil sau sistem compatibil nedeterminat.');
    break;
  end;
  x = SubsDesc(A(1: n, 1: n), A(:, n + 1));
end;