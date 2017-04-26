function ploteazaExemple(exemple,Marker,Color)

if nargin < 2
    Marker = 'o';
    Color = 'b';
end

plot(exemple(:,1),exemple(:,2),[Marker Color]);