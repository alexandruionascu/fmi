function x = random()
  r = rand();
  if r < 1/3
    x = 1;
    return;
  end
  
  if r < 2/3
    x = 2;
    return;
  end
  
  x = 3;
 endfunction
  
  