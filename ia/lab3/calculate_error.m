function error = calculate_error(training, classified)
  n = size(training)(1);
  good = 0;
  for i = 1:n
    if(training(i, 2) == classified(i, 2))
      good = good + 1;
    end
  end
  error = good / n;
end