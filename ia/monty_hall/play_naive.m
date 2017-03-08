function has_won = play_naive
  car = random();
  goat = random();
  has_won = 0;
  if (car == goat)
    has_won = 1;
  end
endfunction