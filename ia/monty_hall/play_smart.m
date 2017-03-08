function has_won = play_smart
  options = {"goat", "goat", "goat"};
  car = random();
  options{car} = "car";
  first_pick = random();
  for i=1:3
    if(strcmp(options{i},"goat") && i != first_pick)
      reveal = i;    
    endif
  endfor
  has_won = 0;
  remaining = 6 - (first_pick + reveal);
  if(remaining == car)
    has_won = 1;
  endif
endfunction
  