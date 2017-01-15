close all;
clear all;
clc;

kSize = 10;
sigma = 10;

for i = 0:kSize-1
    G(i+1) = exp(-(i-(kSize-1)/2)^2/(2*sigma^2));
end
temp = G;
G = G./sum(temp);

img = rgb2gray(imread('lena.bmp'));
Hfct = psf2otf(G, [512, 512]);

imgDFTmatlab = fft2(img);
out = abs(ifft2(Hfct.*fft2(img)));
imagesc(out);colormap(gray);

%%
load('imgDFT.csv');
clear('imgDFTc');
index = 1;
for i=1:2:size(imgDFT,2)
    imgDFTc(:,index) = imgDFT(:,i)+j*imgDFT(:,i+1);
    index = index + 1;
end

%%
load('tempFile.csv');
clear('tempFilec');
index = 1;
for i=1:2:size(tempFile,2)
    tempFilec(:,index) = tempFile(:,i)+j*tempFile(:,i+1);
    index = index + 1;
end

%%
load('filterGaussMul.csv');
clear('filterGaussMulc');
index = 1;
for i=1:2:size(filterGaussMul,2)
    filterGaussMulc(:,index) = filterGaussMul(:,i)+j*filterGaussMul(:,i+1);
    index = index + 1;
end

%%
load('gaussKfct.csv');
clear('gaussKfctc');
index = 1;
for i=1:2:size(gaussKfct,2)
    gaussKfctc(:,index) = gaussKfct(:,i)+j*gaussKfct(:,i+1);
    index = index + 1;
end

%%
out = abs(ifft2(Hfct.*imgDFTc));
imagesc(out);colormap(gray);




%%
clear all;
close all;

img = rgb2gray(imread('lena.bmp'));

load('gaussKfctFile.csv');
load('complexIFile.csv');
load('invDFTgaussFile.csv');
load('tempFile.csv');


index = 1;
for i=1:2:size(gaussKfctFile,2)
    gaussKfctFilec(:,index) = gaussKfctFile(:,i)+j*gaussKfctFile(:,i+1);
    index = index + 1;
end

index = 1;
for i=1:2:size(complexIFile,2)
    complexIFilec(:,index) = complexIFile(:,i)+j*complexIFile(:,i+1);
    index = index + 1;
end

index = 1;
for i=1:2:size(invDFTgaussFile,2)
    invDFTgaussFilec(:,index) = invDFTgaussFile(:,i)+j*invDFTgaussFile(:,i+1);
    index = index + 1;
end

index = 1;
for i=1:2:size(tempFile,2)
    tempFilec(:,index) = tempFile(:,i)+j*tempFile(:,i+1);
    index = index + 1;
end

%%

% imagesc(abs(ifft2(gaussKfctFile.*complexIFile)));colormap(gray);
 
out = abs(ifft2(gaussKfctFilec.*fft2(img)));
imagesc(out);colormap(gray);