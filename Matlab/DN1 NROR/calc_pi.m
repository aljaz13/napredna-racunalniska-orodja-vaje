st_tock=input("stevilo tock: ");

tocke_na_loku_kroznice = @(r, fi) [r * cos(fi); r * sin(fi)];

[tocke_v_krogu, tocke_v_kvadratu] = mcc_pi(st_tock);

[pi_vrednost, pi_odstopanje]=area_pi(tocke_v_krogu, tocke_v_kvadratu);

fprintf('π vrednost: %.6f\n', pi_vrednost);
fprintf('Odstopanje: %.6f\n', pi_odstopanje);

function [pi_vrednost, pi_odstopanje] = area_pi(tocke_v_krogu, tocke_v_kvadratu)
    pi_vrednost = 4 * size(tocke_v_krogu) / size(tocke_v_kvadratu);
    pi_odstopanje = pi_vrednost - pi;
end