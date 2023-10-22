figure;
plot(tocke_v_kvadratu(:, 1), tocke_v_kvadratu(:, 2), 'b.', 'MarkerSize', 5);
hold on;
plot(tocke_v_krogu(:, 1), tocke_v_krogu(:, 2), 'r.', 'MarkerSize', 5);

fi = linspace(0, 2 * pi, 1000);
kroznica = tocke_na_loku_kroznice(1, fi);
plot(kroznica(1, :), kroznica(2, :), 'k', 'LineWidth', 2);

% označba grafa
title('Metoda Monte Carlo');
xlabel('x-koordinate točk');
ylabel('y-koordinate točk');
legend('točke zunaj kroga','točke v krogu','krožnica')

axis equal;
hold off;