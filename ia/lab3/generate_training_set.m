function training_set = generate_training_set(n, c)
  training_set = rand(n, 2) * 4 * c;
  for i=1:n
    p = training_set(i, 1) / (training_set(i, 1) + c);
    if rand() < p
      training_set(i, 2) = 1;     
    else
       training_set(i, 2) = 0;
    end
  end
end