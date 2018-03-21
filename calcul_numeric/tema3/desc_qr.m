function [x,Q,R] = desc_qr(A,b)
    n = length(b);
    Q = zeros(n,n);
    R = zeros(n,n);

    sum = 0;
    for i = 1:n
        sum = sum + A(i,1).^2;
    end
    
    R(1,1) = sqrt(sum);
    
    for i = 1:n
        Q(i,1) = A(i,1) / R(1,1);
    end;
    
    for j = 2:n
        sum = 0;
        for s=1:n
            sum = sum + Q(s,1) * A(s,j);
        end
        R(1,j) = sum;
    end


    for k = 2:n
        sum_a = 0;
        sum_r = 0;
        for i = 1:n
            sum_a = sum_a + A(i,k).^2;
        end
        for i = 1:(k-1)
            sum_r = sum_r + R(i,k).^2;
        end
        R(k,k) = sqrt(sum_a - sum_r);
        
        for i=1:n
            sum = 0;
            for s=1:(k-1)
                sum = sum + Q(i,s) * R(s,k);
            end
            Q(i,k) = (A(i,k)-sum)/R(k,k);
        end
        
        for j = (k+1):n
            sum =0;
            for s=1:n
                sum = sum + Q(s,k)*A(s,j);
            end
            R(k,j) = sum;
        end
    end

   x = sub_desc(R,Q'*b);
end