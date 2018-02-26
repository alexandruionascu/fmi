function x = binary_search(f, a, b, eps)
  while (abs(a - b) > eps)
       x = (a + b) / 2;
       if f(x) == 0
          return;
       else if f(a) * f(x) < 0
          b = x;
       else
          a = x;
       end
  end
end