close all;
clear all;
clc;

a = 0.01;
b = 0.01;

t = 1; % temps en s

img = double(rgb2gray(imread('lena.bmp')));
[H L] = size(img);

for u=1:H
    for v = 1:L
        H(u,v) = t*(sin(pi*(a*u+b*v))*exp(-i*pi*(a*u+v*b)))/(pi*(a*u+v*b));
    end
end

G = fft2(img).*H;

K = 0.001;
T = conj(H)./(abs(H.*H)+K); % Wiener filter reconstructio
F = G.*T;

%% 
subplot(1,3,1);imagesc(img);colormap(gray);title('Image originale');
subplot(1,3,2);imagesc(abs(ifft2(G)));colormap(gray);title('Image floutée');
subplot(1,3,3);imagesc(abs(ifft2(F)));colormap(gray);title('Image reconstruite (Wiener)');

%%

close all;

M = 30;
% motion = zeros(M,M);
% motion(1,:) = ones(M,1);
motion = ones(M,1)'./[M*2,M*ones(M-2,1)',M*2];
motion2 = fspecial('motion',M,0);

h = filter2(motion,img);

Pf = psf2otf(motion, [512, 512]);
h2 = ifft2(Pf.*fft2(img));

subplot(1,3,1);imagesc(img);colormap(gray);title('Image originale');
subplot(1,3,2);imagesc(h);colormap(gray);title('Motion');
subplot(1,3,3);imagesc(abs(h2));colormap(gray);title('Motion');

%%
close all;
clear all;
clc;


img = double(rgb2gray(imread('lena.bmp')));

K = fspecial('gaussian',10,10);

%K = fspecial('motion',20,10);
imgMotion = imfilter(img,K);

Hfct = psf2otf(K, [512, 512]);
gamma = 0.1;
Pfct = psf2otf([0 -1 0; -1 4 -1; 0 -1 0], [512, 512]);
%Pfct = psf2otf([1 2 3 4;5 6 7 8;9 10 11 12;13 14 15 16], [512, 512]);
F = conj(Hfct)./( conj(Hfct).*Hfct+gamma*conj(Pfct).*Pfct).*fft2(imgMotion);

subplot(1,3,1);imagesc(img);colormap(gray);title('Image originale');
subplot(1,3,2);imagesc(imgMotion);colormap(gray);title('Image floutée');
subplot(1,3,3);imagesc(abs(ifft2(F)));colormap(gray);title('Image reconstruite (CLS)');

%% Motion 
% Construct an ideal line segment with the desired length and angle,
% centered at the center coefficient of h.
% For each coefficient location (i,j), compute the nearest 
% distance between that location and the ideal line segment.
% h = max(1 - nearest_distance, 0);
% Normalize h:h = h/(sum(h(:)))


