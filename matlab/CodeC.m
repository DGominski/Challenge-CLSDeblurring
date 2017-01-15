close all;
clear all;
clc;

% Circular shift

mat = [1 2 3 4;5 6 7 8;9 10 11 12;13 14 15 16];

mat2 = zeros(size(mat));

for i =1:size(mat,1)
    for y =1:size(mat,2)
        mat2(abs(i-size(mat,1)-1),abs(y-size(mat,2)-1))  = mat(i,y);
    end
end