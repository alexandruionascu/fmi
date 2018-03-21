function [x, L] = desc_cholesky(A,b)
   if( A(1,1) <= 0 )
       print('A nu este pozitiv definita');
       return;
   end
   
   n = length(b);
   L(1,1) = sqrt(A(1,1));
   for i = 2:n
       L(i,1) = A(i,1) / L(1,1);
   end

    for k = 2:n
        sum = 0;
        for s=1:k-1
            sum = sum + L(k,s).^2;
        end
        result = A(k,k) - sum;
        if result <= 0
            disp('A nu este pozitiv definita');
            return;
        end
        L(k,k) = sqrt(result);
        for i = k+1 : n
            sum = 0;
            for s = 1:k-1
                sum = sum + L(i,s) * L(k,s);
            end
            L(i,k) = ( A(i,k) - sum ) / L(k,k);
        end
    end
   
    y = sub_asc(L,b);
    x = sub_desc(L',y);
end