clear all;
close all;
clc;

g = 0.1;

E = rgb2gray(imread('lena.bmp'));
figure;
imagesc(E); colormap gray;

K = fspecial('gaussian',[7 7],2);
% K = fspecial('motion',20,50);
S = imfilter(E,K);

NOISE = wgn(512,512,20);
S = S + uint8(NOISE);

figure;
imagesc(S); colormap gray;

Pf = psf2otf([0 -1 0; -1 4 -1; 0 -1 0], [512, 512]);
Sf = fft2(S);
Kf = psf2otf(K, [512, 512]);

Ef = (1./Kf) .* ( conj(Kf).*Kf ./ ( conj(Kf).*Kf + g*conj(Pf).*Pf)) .* Sf;

Er = abs(ifft2(Ef));
figure;
imagesc(Er); colormap gray;