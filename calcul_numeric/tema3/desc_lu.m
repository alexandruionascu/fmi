function [L,U,x] = desc_lu(A,b)
    n = length(b);
    x = zeros(n);
    U = zeros(n,n);
    L = zeros(n,n);

    for j=1:n
        U(1,j) = A(1,j);
    end
    if( U(1,1) == 0)
        print('A nu admite factorizare LU');
        return;    
    end
    for i=1:n
        L(i,1) = A(i,1) / U(1,1);
    end
 
    for i=2:n
        for j=i:n            
            sum = 0;
            for s = 1:i-1
                sum = sum + L(i,s) * U(s,j);
            end
            U(i,j) = A(i,j) - sum;
         end
        if ( U(i,i) == 0 )
           print('A nu admite factorizare LU');
           return; 
        end
        for t = i:n
            sum = 0;
            for s=1:i-1
                sum = sum + L(t,s) * U(s,i);
            end
            L(t,i) = ( A(t,i) - sum ) / U(i,i);
        end        
    end
    
    y = sub_asc(L,b);    
    x = sub_desc(U,y);
end