gets.to_i.times{x,y,r,p,q,l=gets.split.map(&:to_i);d=Math.hypot(p-x,q-y);p(x==p&&y==q&&r==l ?-1:r>d||l>d? 0:(r+l<=>d)+1)}
