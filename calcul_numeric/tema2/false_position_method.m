function x = false_position_method(f, a, b, eps)
  x = (a * f(b) - b * f(a)) / (f(b) - f(a));
  x_prev = 0;
  while true
    x_prev = x;
    if f(x) == 0
      break
    elseif f(a) * f(x) < 0
      b = x;
      x = (a * f(b) - b * f(a)) / (f(b) - f(a));
    else
      a = x;
      x = (a * f(b) - b * f(a)) / (f(b) - f(a));      
    end
    
    if abs(x - x_prev) / abs(x_prev) < eps  
      break;
    end
  end
end