(* ::Package:: *)

mccpi[sttock_]:=Module[{x,y,razdalja,tockevkrogu,tockevkvadratu},
x=RandomReal[{-1,1},sttock];
y=RandomReal[{-1,1},sttock];
razdalja=x^2+y^2;
tockevkrogu=Select[Transpose[{x,y}],Total[#^2]<=1&];
tockevkvadratu=Transpose[{x,y}];
{tockevkrogu,tockevkvadratu}];
