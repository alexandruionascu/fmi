function classified = classify(x, c)
  n = size(x)(1);
  classified = x;
  for i=1:n
    
    if (x(i)(1) / (x(i)(1) + c)) > 0.5
      classified(i, 2) = 0;
    else
      classified(i, 2) = 1;
    end    
  end

end