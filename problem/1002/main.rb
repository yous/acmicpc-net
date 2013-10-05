gets.to_i.times{x,y,r,p,q,l=gets.split.map(&:to_i);d=Math.hypot(p-x,q-y);m=r+l;n=(r-l).abs;p(x==p&&y==q&&r==l ?-1:m<d||n>d ?0:m==d||n==d ?1:2)}
