function [tocke_v_krogu, tocke_v_kvadratu] = mcc_pi(st_tock)

    x = 2*rand(st_tock, 1)-1;
    y = 2*rand(st_tock, 1)-1;

    razdalja = x.^2 + y.^2;
    tocke_v_krogu = [x(razdalja <= 1), y(razdalja <= 1)];
    tocke_v_kvadratu = [x, y];
end