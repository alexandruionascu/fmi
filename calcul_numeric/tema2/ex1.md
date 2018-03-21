8x^3 + 4x - 1 = 0, x din [0, 1]
f'(x) = 24x^2 + 4
a) functia e crescatoare / derivata f'(x) > 0
   f(0) = -1
   f(1) = 11
   f continua
   inseamna ca functia e continua crescatoare pe [-1, 11]
   asadar avem o singura solutie
   
b) Metoda Newton - Raphson 
alegem x0 = 0.5
x1 = 0.5 - f(0.5) / f'(0.5)
   = 0.5 - 2 / 10
   = 0.3
x2 = 0.3 - f(0.3) / f'(0.3)
   = 0.3 - 0.216 / 6.16
   = 0.3 - 0.035
   = 0.265

   Metoda secantei
   x0 = 0
   x1 = 1
   x2 = (x0 * f(x1) - x1 * f(x0) ) / (f(x1) - f(x0))
      = (0 - 1 * (-1) ) / (11 - (-1))
      = 1 / 12
      = 0.08(3)
   
   Metoda pozitiei false
   a = 0
   b = 1
   x0 = (a0 * f(b0) - b0 * f(a0)) / (f(b0) - f(a0))
      = 1 / 12
   x2 = (1/12 * f(b1) - b1 * f(1/12)) / (f(b1) - f(1/12))
      = (1/12 * 11 - 1.32) / (11 + 1.32)
      = -0.4 / 12.32
      = 0.032
