function monty_hall(n)
  naive_win = 0;
  smart_win = 0;
  for i=1:n
    naive_win += play_naive();
    smart_win += play_smart();
  endfor
  
  disp("Probability for naive strategy is "), disp(naive_win / n);
  disp("Probability for smart strategy is "), disp(smart_win / n);
endfunction