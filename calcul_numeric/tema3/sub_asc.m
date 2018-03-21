function [x] = sub_asc(A,b)   
    n = length(b);
    x = zeros(n);
    x(1) = b(1)/A(1,1);
    
    for i=2:n
        sum = 0;
        for j=1:(i-1)
            sum = sum + A(i,j) * x(j); 
        end
        sum = b(i) - sum;
        x(i) = sum / A(i,i);
    end

end