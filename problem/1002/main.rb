gets.to_i.times{x,y,r,p,q,l=gets.split.map(&:to_i);d=Math.hypot(p-x,q-y);m=r+l;n=(r-l).abs;p(d==0&&r==l ?-1:d<n|m<d ?0:n<d|d<m ?2:1)}
