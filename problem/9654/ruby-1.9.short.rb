# encoding: utf-8
"SHIP NAME,CLASS,DEPLOYMENT,IN SERVICE,N2 Bomber,Heavy Fighter,Limited,21,J-Type 327,Light Combat,Unlimited,1,NX Cruiser,Medium Fighter,Limited,18,N1 Starfighter,Medium Fighter,Unlimited,25,Royal Cruiser,Light Combat,Limited,4".split(",").each_slice(4){|a|puts"%-15s%-15s%-11s%-10s"%a}

# [
#   %w(SHIP\ NAME CLASS DEPLOYMENT IN\ SERVICE),
#   %w(N2\ Bomber Heavy\ Fighter Limited 21),
#   %w(J-Type\ 327 Light\ Combat Unlimited 1),
#   %w(NX\ Cruiser Medium\ Fighter Limited 18),
#   %w(N1\ Starfighter Medium\ Fighter Unlimited 25),
#   %w(Royal\ Cruiser Light\ Combat Limited 4)
# ].each do |args|
#   puts format("%-15s%-15s%-11s%-10s", args)
# end
