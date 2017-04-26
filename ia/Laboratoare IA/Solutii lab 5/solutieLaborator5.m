%nnd2n1, nnd2n2
%reprezentari grafice pt diferite functii de transfer
%pentru functia hardlim
n = -5:0.01:5;
plot(n,hardlim(n))
set(gca,'dataaspectratio',[1 1 1],'xgrid','on','ygrid','on')
%pentru celelalte functii codul este similar

%nnd3pc
net = newp([-1 1; -1 1;-1 1], 1);
net.IW{1} = [0 1 0];
net.b{1} = 0;
view(net);
exemple = rand(3,10)*2-1;
sim(net,exemple)

%norul de puncte
puncte = rand(2,1000)*2-1;
figure, hold on;
etichete = zeros(1,1000);
for i =1:size(puncte,2)
    etichete(i) = (puncte(1,i) - puncte(2,i) >= 0);
    if(puncte(1,i) - puncte(2,i) >= 0)
        plot(puncte(1,i),puncte(2,i),['xr']);
    else
        plot(puncte(1,i),puncte(2,i),['ob']);
    end
end

net = newp([-1 1; -1 1;], 1);
net.IW{1} = [1 -1];
net.b{1} = 0;
rez = sim(net,puncte);
isequal(rez,etichete)
%vezi care e functia de transfer
net.layers{1}.transferFcn
plotpc(net.IW{1},net.b{1})
%nnd4db

%retea pt OR
net = newp([-1 1; -1 1;], 1);
net.IW{1} = [1 1];
net.b{1} = -0.5;
puncte = [ [0 0]', [0 1]', [1 0]', [1 1]'];
etichete = [0 1 1 1];
rez = sim(net,puncte);
isequal(rez,etichete)

%retea pentur AND
net = newp([-1 1; -1 1;], 1);
net.IW{1} = [1 1];
net.b{1} = -1.5;
puncte = [ [0 0]', [0 1]', [1 0]', [1 1]'];
etichete = [0 0 0 1];
rez = sim(net,puncte);
isequal(rez,etichete)

%nu exista pentru XOR o rete cu un perceptron care sa separe punctele