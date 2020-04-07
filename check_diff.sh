#!/bin/bash

GREEN="\e[32m"
RED="\e[31m"
EOC="\e[0m"

echo ""
echo "batman.s"
./asm champions/batman.s
hexdump -vC champions/batman.cor > my_file
./resources/vm_champs/asm champions_disassemble/batman.s
./asm champions_disassemble/batman.cor
./resources/vm_champs/asm champions_disassemble/batman.s
hexdump -vC champions_disassemble/batman.cor > original_after_disassemble
./resources/vm_champs/asm champions/batman.s
hexdump -vC champions/batman.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original my_file_after_disassemble champions/*.cor 
echo "bee_gees.s"
./asm champions/bee_gees.s
hexdump -vC champions/bee_gees.cor > my_file
./resources/vm_champs/asm champions_disassemble/bee_gees.s
./asm champions_disassemble/bee_gees.cor
./resources/vm_champs/asm champions_disassemble/bee_gees.s
hexdump -vC champions_disassemble/bee_gees.cor > original_after_disassemble
./resources/vm_champs/asm champions/bee_gees.s
hexdump -vC champions/bee_gees.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "bigzork.s"
./asm champions/bigzork.s
hexdump -vC champions/bigzork.cor > my_file
./resources/vm_champs/asm champions_disassemble/bigzork.s
./asm champions_disassemble/bigzork.cor
./resources/vm_champs/asm champions_disassemble/bigzork.s
hexdump -vC champions_disassemble/bigzork.cor > original_after_disassemble
./resources/vm_champs/asm champions/bigzork.s
hexdump -vC champions/bigzork.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "fluttershy.s"
./asm champions/fluttershy.s
hexdump -vC champions/fluttershy.cor > my_file
./resources/vm_champs/asm champions_disassemble/fluttershy.s
./asm champions_disassemble/fluttershy.cor
./resources/vm_champs/asm champions_disassemble/fluttershy.s
hexdump -vC champions_disassemble/fluttershy.cor > original_after_disassemble
./resources/vm_champs/asm champions/fluttershy.s
hexdump -vC champions/fluttershy.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "helltrain.s"
./asm champions/helltrain.s
hexdump -vC champions/helltrain.cor > my_file
./resources/vm_champs/asm champions_disassemble/helltrain.s
./asm champions_disassemble/helltrain.cor
./resources/vm_champs/asm champions_disassemble/helltrain.s
hexdump -vC champions_disassemble/helltrain.cor > original_after_disassemble
./resources/vm_champs/asm champions/helltrain.s
hexdump -vC champions/helltrain.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "turtle.s"
./asm champions/turtle.s
hexdump -vC champions/turtle.cor > my_file
./resources/vm_champs/asm champions_disassemble/turtle.s
./asm champions_disassemble/turtle.cor
./resources/vm_champs/asm champions_disassemble/turtle.s
hexdump -vC champions_disassemble/turtle.cor > original_after_disassemble
./resources/vm_champs/asm champions/turtle.s
hexdump -vC champions/turtle.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "zork.s"
./asm champions/zork.s
hexdump -vC champions/zork.cor > my_file
./resources/vm_champs/asm champions_disassemble/zork.s
./asm champions_disassemble/zork.cor
./resources/vm_champs/asm champions_disassemble/zork.s
hexdump -vC champions_disassemble/zork.cor > original_after_disassemble
./resources/vm_champs/asm champions/zork.s
hexdump -vC champions/zork.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "42.s"
./asm champions/42.s
hexdump -vC champions/42.cor > my_file
./resources/vm_champs/asm champions_disassemble/42.s
./asm champions_disassemble/42.cor
./resources/vm_champs/asm champions_disassemble/42.s
hexdump -vC champions_disassemble/42.cor > original_after_disassemble
./resources/vm_champs/asm champions/42.s
hexdump -vC champions/42.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "Backward.s"
./asm champions/Backward.s
hexdump -vC champions/Backward.cor > my_file
./resources/vm_champs/asm champions_disassemble/Backward.s
./asm champions_disassemble/Backward.cor
./resources/vm_champs/asm champions_disassemble/Backward.s
hexdump -vC champions_disassemble/Backward.cor > original_after_disassemble
./resources/vm_champs/asm champions/Backward.s
hexdump -vC champions/Backward.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "barriere.s"
./asm champions/barriere.s
hexdump -vC champions/barriere.cor > my_file
./resources/vm_champs/asm champions_disassemble/barriere.s
./asm champions_disassemble/barriere.cor
./resources/vm_champs/asm champions_disassemble/barriere.s
hexdump -vC champions_disassemble/barriere.cor > original_after_disassemble
./resources/vm_champs/asm champions/barriere.s
hexdump -vC champions/barriere.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "Car.s"
./asm champions/Car.s
hexdump -vC champions/Car.cor > my_file
./resources/vm_champs/asm champions_disassemble/Car.s
./asm champions_disassemble/Car.cor
./resources/vm_champs/asm champions_disassemble/Car.s
hexdump -vC champions_disassemble/Car.cor > original_after_disassemble
./resources/vm_champs/asm champions/Car.s
hexdump -vC champions/Car.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "Death.s"
./asm champions/Death.s
hexdump -vC champions/Death.cor > my_file
./resources/vm_champs/asm champions_disassemble/Death.s
./asm champions_disassemble/Death.cor
./resources/vm_champs/asm champions_disassemble/Death.s
hexdump -vC champions_disassemble/Death.cor > original_after_disassemble
./resources/vm_champs/asm champions/Death.s
hexdump -vC champions/Death.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "ex.s"
./asm champions/ex.s
hexdump -vC champions/ex.cor > my_file
./resources/vm_champs/asm champions_disassemble/ex.s
./asm champions_disassemble/ex.cor
./resources/vm_champs/asm champions_disassemble/ex.s
hexdump -vC champions_disassemble/ex.cor > original_after_disassemble
./resources/vm_champs/asm champions/ex.s
hexdump -vC champions/ex.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "Gagnant.s"
./asm champions/Gagnant.s
hexdump -vC champions/Gagnant.cor > my_file
./resources/vm_champs/asm champions_disassemble/Gagnant.s
./asm champions_disassemble/Gagnant.cor
./resources/vm_champs/asm champions_disassemble/Gagnant.s
hexdump -vC champions_disassemble/Gagnant.cor > original_after_disassemble
./resources/vm_champs/asm champions/Gagnant.s
hexdump -vC champions/Gagnant.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "jumper.s"
./asm champions/jumper.s
hexdump -vC champions/jumper.cor > my_file
./resources/vm_champs/asm champions_disassemble/jumper.s
./asm champions_disassemble/jumper.cor
./resources/vm_champs/asm champions_disassemble/jumper.s
hexdump -vC champions_disassemble/jumper.cor > original_after_disassemble
./resources/vm_champs/asm champions/jumper.s
hexdump -vC champions/jumper.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "lde.s"
./asm champions/lde.s
hexdump -vC champions/lde.cor > my_file
./resources/vm_champs/asm champions_disassemble/lde.s
./asm champions_disassemble/lde.cor
./resources/vm_champs/asm champions_disassemble/lde.s
hexdump -vC champions_disassemble/lde.cor > original_after_disassemble
./resources/vm_champs/asm champions/lde.s
hexdump -vC champions/lde.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "leeloo.s"
./asm champions/leeloo.s
hexdump -vC champions/leeloo.cor > my_file
./resources/vm_champs/asm champions_disassemble/leeloo.s
./asm champions_disassemble/leeloo.cor
./resources/vm_champs/asm champions_disassemble/leeloo.s
hexdump -vC champions_disassemble/leeloo.cor > original_after_disassemble
./resources/vm_champs/asm champions/leeloo.s
hexdump -vC champions/leeloo.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "mat.s"
./asm champions/mat.s
hexdump -vC champions/mat.cor > my_file
./resources/vm_champs/asm champions_disassemble/mat.s
./asm champions_disassemble/mat.cor
./resources/vm_champs/asm champions_disassemble/mat.s
hexdump -vC champions_disassemble/mat.cor > original_after_disassemble
./resources/vm_champs/asm champions/mat.s
hexdump -vC champions/mat.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "maxidef.s"
./asm champions/maxidef.s
hexdump -vC champions/maxidef.cor > my_file
./resources/vm_champs/asm champions_disassemble/maxidef.s
./asm champions_disassemble/maxidef.cor
./resources/vm_champs/asm champions_disassemble/maxidef.s
hexdump -vC champions_disassemble/maxidef.cor > original_after_disassemble
./resources/vm_champs/asm champions/maxidef.s
hexdump -vC champions/maxidef.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "mortel.s"
./asm champions/mortel.s
hexdump -vC champions/mortel.cor > my_file
./resources/vm_champs/asm champions_disassemble/mortel.s
./asm champions_disassemble/mortel.cor
./resources/vm_champs/asm champions_disassemble/mortel.s
hexdump -vC champions_disassemble/mortel.cor > original_after_disassemble
./resources/vm_champs/asm champions/mortel.s
hexdump -vC champions/mortel.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "new.s"
./asm champions/new.s
hexdump -vC champions/new.cor > my_file
./resources/vm_champs/asm champions_disassemble/new.s
./asm champions_disassemble/new.cor
./resources/vm_champs/asm champions_disassemble/new.s
hexdump -vC champions_disassemble/new.cor > original_after_disassemble
./resources/vm_champs/asm champions/new.s
hexdump -vC champions/new.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "Octobre_Rouge_V4.2.s"
./asm champions/Octobre_Rouge_V4.2.s
hexdump -vC champions/Octobre_Rouge_V4.2.cor > my_file
./resources/vm_champs/asm champions_disassemble/Octobre_Rouge_V4.2.s
./asm champions_disassemble/Octobre_Rouge_V4.2.cor
./resources/vm_champs/asm champions_disassemble/Octobre_Rouge_V4.2.s
hexdump -vC champions_disassemble/Octobre_Rouge_V4.2.cor > original_after_disassemble
./resources/vm_champs/asm champions/Octobre_Rouge_V4.2.s
hexdump -vC champions/Octobre_Rouge_V4.2.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "sebc.s"
./asm champions/sebc.s
hexdump -vC champions/sebc.cor > my_file
./resources/vm_champs/asm champions_disassemble/sebc.s
./asm champions_disassemble/sebc.cor
./resources/vm_champs/asm champions_disassemble/sebc.s
hexdump -vC champions_disassemble/sebc.cor > original_after_disassemble
./resources/vm_champs/asm champions/sebc.s
hexdump -vC champions/sebc.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "slider2.s"
./asm champions/slider2.s
hexdump -vC champions/slider2.cor > my_file
./resources/vm_champs/asm champions_disassemble/slider2.s
./asm champions_disassemble/slider2.cor
./resources/vm_champs/asm champions_disassemble/slider2.s
hexdump -vC champions_disassemble/slider2.cor > original_after_disassemble
./resources/vm_champs/asm champions/slider2.s
hexdump -vC champions/slider2.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "Survivor.s"
./asm champions/Survivor.s
hexdump -vC champions/Survivor.cor > my_file
./resources/vm_champs/asm champions_disassemble/Survivor.s
./asm champions_disassemble/Survivor.cor
./resources/vm_champs/asm champions_disassemble/Survivor.s
hexdump -vC champions_disassemble/Survivor.cor > original_after_disassemble
./resources/vm_champs/asm champions/Survivor.s
hexdump -vC champions/Survivor.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "tdc2.s"
./asm champions/tdc2.s
hexdump -vC champions/tdc2.cor > my_file
./resources/vm_champs/asm champions_disassemble/tdc2.s
./asm champions_disassemble/tdc2.cor
./resources/vm_champs/asm champions_disassemble/tdc2.s
hexdump -vC champions_disassemble/tdc2.cor > original_after_disassemble
./resources/vm_champs/asm champions/tdc2.s
hexdump -vC champions/tdc2.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "tdc3.s"
./asm champions/tdc3.s
hexdump -vC champions/tdc3.cor > my_file
./resources/vm_champs/asm champions_disassemble/tdc3.s
./asm champions_disassemble/tdc3.cor
./resources/vm_champs/asm champions_disassemble/tdc3.s
hexdump -vC champions_disassemble/tdc3.cor > original_after_disassemble
./resources/vm_champs/asm champions/tdc3.s
hexdump -vC champions/tdc3.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "tdc4.s"
./asm champions/tdc4.s
hexdump -vC champions/tdc4.cor > my_file
./resources/vm_champs/asm champions_disassemble/tdc4.s
./asm champions_disassemble/tdc4.cor
./resources/vm_champs/asm champions_disassemble/tdc4.s
hexdump -vC champions_disassemble/tdc4.cor > original_after_disassemble
./resources/vm_champs/asm champions/tdc4.s
hexdump -vC champions/tdc4.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "Torpille.s"
./asm champions/Torpille.s
hexdump -vC champions/Torpille.cor > my_file
./resources/vm_champs/asm champions_disassemble/Torpille.s
./asm champions_disassemble/Torpille.cor
./resources/vm_champs/asm champions_disassemble/Torpille.s
hexdump -vC champions_disassemble/Torpille.cor > original_after_disassemble
./resources/vm_champs/asm champions/Torpille.s
hexdump -vC champions/Torpille.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "toto.s"
./asm champions/toto.s
hexdump -vC champions/toto.cor > my_file
./resources/vm_champs/asm champions_disassemble/toto.s
./asm champions_disassemble/toto.cor
./resources/vm_champs/asm champions_disassemble/toto.s
hexdump -vC champions_disassemble/toto.cor > original_after_disassemble
./resources/vm_champs/asm champions/toto.s
hexdump -vC champions/toto.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "_.s"
./asm champions/_.s
hexdump -vC champions/_.cor > my_file
./resources/vm_champs/asm champions_disassemble/_.s
./asm champions_disassemble/_.cor
./resources/vm_champs/asm champions_disassemble/_.s
hexdump -vC champions_disassemble/_.cor > original_after_disassemble
./resources/vm_champs/asm champions/_.s
hexdump -vC champions/_.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "_honeybadger.s"
./asm champions/_honeybadger.s
hexdump -vC champions/_honeybadger.cor > my_file
./resources/vm_champs/asm champions_disassemble/_honeybadger.s
./asm champions_disassemble/_honeybadger.cor
./resources/vm_champs/asm champions_disassemble/_honeybadger.s
hexdump -vC champions_disassemble/_honeybadger.cor > original_after_disassemble
./resources/vm_champs/asm champions/_honeybadger.s
hexdump -vC champions/_honeybadger.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "Asombra.s"
./asm champions/Asombra.s
hexdump -vC champions/Asombra.cor > my_file
./resources/vm_champs/asm champions_disassemble/Asombra.s
./asm champions_disassemble/Asombra.cor
./resources/vm_champs/asm champions_disassemble/Asombra.s
hexdump -vC champions_disassemble/Asombra.cor > original_after_disassemble
./resources/vm_champs/asm champions/Asombra.s
hexdump -vC champions/Asombra.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "Bazou.s"
./asm champions/Bazou.s
hexdump -vC champions/Bazou.cor > my_file
./resources/vm_champs/asm champions_disassemble/Bazou.s
./asm champions_disassemble/Bazou.cor
./resources/vm_champs/asm champions_disassemble/Bazou.s
hexdump -vC champions_disassemble/Bazou.cor > original_after_disassemble
./resources/vm_champs/asm champions/Bazou.s
hexdump -vC champions/Bazou.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "big_feet.s"
./asm champions/big_feet.s
hexdump -vC champions/big_feet.cor > my_file
./resources/vm_champs/asm champions_disassemble/big_feet.s
./asm champions_disassemble/big_feet.cor
./resources/vm_champs/asm champions_disassemble/big_feet.s
hexdump -vC champions_disassemble/big_feet.cor > original_after_disassemble
./resources/vm_champs/asm champions/big_feet.s
hexdump -vC champions/big_feet.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "casimir.s"
./asm champions/casimir.s
hexdump -vC champions/casimir.cor > my_file
./resources/vm_champs/asm champions_disassemble/casimir.s
./asm champions_disassemble/casimir.cor
./resources/vm_champs/asm champions_disassemble/casimir.s
hexdump -vC champions_disassemble/casimir.cor > original_after_disassemble
./resources/vm_champs/asm champions/casimir.s
hexdump -vC champions/casimir.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "champ.s"
./asm champions/champ.s
hexdump -vC champions/champ.cor > my_file
./resources/vm_champs/asm champions_disassemble/champ.s
./asm champions_disassemble/champ.cor
./resources/vm_champs/asm champions_disassemble/champ.s
hexdump -vC champions_disassemble/champ.cor > original_after_disassemble
./resources/vm_champs/asm champions/champ.s
hexdump -vC champions/champ.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "Code_eater.s"
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
./asm champions/Code_eater.s
hexdump -vC champions/Code_eater.cor > my_file
./resources/vm_champs/asm champions_disassemble/Code_eater.s
./asm champions_disassemble/Code_eater.cor
./resources/vm_champs/asm champions_disassemble/Code_eater.s
hexdump -vC champions_disassemble/Code_eater.cor > original_after_disassemble
./resources/vm_champs/asm champions/Code_eater.s
hexdump -vC champions/Code_eater.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "corelol.s"
./asm champions/corelol.s
hexdump -vC champions/corelol.cor > my_file
./resources/vm_champs/asm champions_disassemble/corelol.s
./asm champions_disassemble/corelol.cor
./resources/vm_champs/asm champions_disassemble/corelol.s
hexdump -vC champions_disassemble/corelol.cor > original_after_disassemble
./resources/vm_champs/asm champions/corelol.s
hexdump -vC champions/corelol.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "darksasuke.s"
./asm champions/darksasuke.s
hexdump -vC champions/darksasuke.cor > my_file
./resources/vm_champs/asm champions_disassemble/darksasuke.s
./asm champions_disassemble/darksasuke.cor
./resources/vm_champs/asm champions_disassemble/darksasuke.s
hexdump -vC champions_disassemble/darksasuke.cor > original_after_disassemble
./resources/vm_champs/asm champions/darksasuke.s
hexdump -vC champions/darksasuke.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "doge.s"
./asm champions/doge.s
hexdump -vC champions/doge.cor > my_file
./resources/vm_champs/asm champions_disassemble/doge.s
./asm champions_disassemble/doge.cor
./resources/vm_champs/asm champions_disassemble/doge.s
hexdump -vC champions_disassemble/doge.cor > original_after_disassemble
./resources/vm_champs/asm champions/doge.s
hexdump -vC champions/doge.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "Douceur_power.s"
./asm champions/Douceur_power.s
hexdump -vC champions/Douceur_power.cor > my_file
./resources/vm_champs/asm champions_disassemble/Douceur_power.s
./asm champions_disassemble/Douceur_power.cor
./resources/vm_champs/asm champions_disassemble/Douceur_power.s
hexdump -vC champions_disassemble/Douceur_power.cor > original_after_disassemble
./resources/vm_champs/asm champions/Douceur_power.s
hexdump -vC champions/Douceur_power.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "dubo.s"
./asm champions/dubo.s
hexdump -vC champions/dubo.cor > my_file
./resources/vm_champs/asm champions_disassemble/dubo.s
./asm champions_disassemble/dubo.cor
./resources/vm_champs/asm champions_disassemble/dubo.s
hexdump -vC champions_disassemble/dubo.cor > original_after_disassemble
./resources/vm_champs/asm champions/dubo.s
hexdump -vC champions/dubo.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "echo.s"
./asm champions/echo.s
hexdump -vC champions/echo.cor > my_file
./resources/vm_champs/asm champions_disassemble/echo.s
./asm champions_disassemble/echo.cor
./resources/vm_champs/asm champions_disassemble/echo.s
hexdump -vC champions_disassemble/echo.cor > original_after_disassemble
./resources/vm_champs/asm champions/echo.s
hexdump -vC champions/echo.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "Eraser.s"
./asm champions/Eraser.s
hexdump -vC champions/Eraser.cor > my_file
./resources/vm_champs/asm champions_disassemble/Eraser.s
./asm champions_disassemble/Eraser.cor
./resources/vm_champs/asm champions_disassemble/Eraser.s
hexdump -vC champions_disassemble/Eraser.cor > original_after_disassemble
./resources/vm_champs/asm champions/Eraser.s
hexdump -vC champions/Eraser.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "Explosive_Kitty.s"
./asm champions/Explosive_Kitty.s
hexdump -vC champions/Explosive_Kitty.cor > my_file
./resources/vm_champs/asm champions_disassemble/Explosive_Kitty.s
./asm champions_disassemble/Explosive_Kitty.cor
./resources/vm_champs/asm champions_disassemble/Explosive_Kitty.s
hexdump -vC champions_disassemble/Explosive_Kitty.cor > original_after_disassemble
./resources/vm_champs/asm champions/Explosive_Kitty.s
hexdump -vC champions/Explosive_Kitty.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "fast.s"
./asm champions/fast.s
hexdump -vC champions/fast.cor > my_file
./resources/vm_champs/asm champions_disassemble/fast.s
./asm champions_disassemble/fast.cor
./resources/vm_champs/asm champions_disassemble/fast.s
hexdump -vC champions_disassemble/fast.cor > original_after_disassemble
./resources/vm_champs/asm champions/fast.s
hexdump -vC champions/fast.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "ForgottenOne.s"
./asm champions/ForgottenOne.s
hexdump -vC champions/ForgottenOne.cor > my_file
./resources/vm_champs/asm champions_disassemble/ForgottenOne.s
./asm champions_disassemble/ForgottenOne.cor
./resources/vm_champs/asm champions_disassemble/ForgottenOne.s
hexdump -vC champions_disassemble/ForgottenOne.cor > original_after_disassemble
./resources/vm_champs/asm champions/ForgottenOne.s
hexdump -vC champions/ForgottenOne.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "gateau.s"
./asm champions/gateau.s
hexdump -vC champions/gateau.cor > my_file
./resources/vm_champs/asm champions_disassemble/gateau.s
./asm champions_disassemble/gateau.cor
./resources/vm_champs/asm champions_disassemble/gateau.s
hexdump -vC champions_disassemble/gateau.cor > original_after_disassemble
./resources/vm_champs/asm champions/gateau.s
hexdump -vC champions/gateau.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "gedeon.s"
./asm champions/gedeon.s
hexdump -vC champions/gedeon.cor > my_file
./resources/vm_champs/asm champions_disassemble/gedeon.s
./asm champions_disassemble/gedeon.cor
./resources/vm_champs/asm champions_disassemble/gedeon.s
hexdump -vC champions_disassemble/gedeon.cor > original_after_disassemble
./resources/vm_champs/asm champions/gedeon.s
hexdump -vC champions/gedeon.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "Hidden.s"
./asm champions/Hidden.s
hexdump -vC champions/Hidden.cor > my_file
./resources/vm_champs/asm champions_disassemble/Hidden.s
./asm champions_disassemble/Hidden.cor
./resources/vm_champs/asm champions_disassemble/Hidden.s
hexdump -vC champions_disassemble/Hidden.cor > original_after_disassemble
./resources/vm_champs/asm champions/Hidden.s
hexdump -vC champions/Hidden.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "Horace.s"
./asm champions/Horace.s
hexdump -vC champions/Horace.cor > my_file
./resources/vm_champs/asm champions_disassemble/Horace.s
./asm champions_disassemble/Horace.cor
./resources/vm_champs/asm champions_disassemble/Horace.s
hexdump -vC champions_disassemble/Horace.cor > original_after_disassemble
./resources/vm_champs/asm champions/Horace.s
hexdump -vC champions/Horace.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "Izi_Miaou.s"
./asm champions/Izi_Miaou.s
hexdump -vC champions/Izi_Miaou.cor > my_file
./resources/vm_champs/asm champions_disassemble/Izi_Miaou.s
./asm champions_disassemble/Izi_Miaou.cor
./resources/vm_champs/asm champions_disassemble/Izi_Miaou.s
hexdump -vC champions_disassemble/Izi_Miaou.cor > original_after_disassemble
./resources/vm_champs/asm champions/Izi_Miaou.s
hexdump -vC champions/Izi_Miaou.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "jinx.s"
./asm champions/jinx.s
hexdump -vC champions/jinx.cor > my_file
./resources/vm_champs/asm champions_disassemble/jinx.s
./asm champions_disassemble/jinx.cor
./resources/vm_champs/asm champions_disassemble/jinx.s
hexdump -vC champions_disassemble/jinx.cor > original_after_disassemble
./resources/vm_champs/asm champions/jinx.s
hexdump -vC champions/jinx.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "justin_bee.s"
./asm champions/justin_bee.s
hexdump -vC champions/justin_bee.cor > my_file
./resources/vm_champs/asm champions_disassemble/justin_bee.s
./asm champions_disassemble/justin_bee.cor
./resources/vm_champs/asm champions_disassemble/justin_bee.s
hexdump -vC champions_disassemble/justin_bee.cor > original_after_disassemble
./resources/vm_champs/asm champions/justin_bee.s
hexdump -vC champions/justin_bee.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "kamelkaze.s"
./asm champions/kamelkaze.s
hexdump -vC champions/kamelkaze.cor > my_file
./resources/vm_champs/asm champions_disassemble/kamelkaze.s
./asm champions_disassemble/kamelkaze.cor
./resources/vm_champs/asm champions_disassemble/kamelkaze.s
hexdump -vC champions_disassemble/kamelkaze.cor > original_after_disassemble
./resources/vm_champs/asm champions/kamelkaze.s
hexdump -vC champions/kamelkaze.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "Kappa.s"
./asm champions/Kappa.s
hexdump -vC champions/Kappa.cor > my_file
./resources/vm_champs/asm champions_disassemble/Kappa.s
./asm champions_disassemble/Kappa.cor
./resources/vm_champs/asm champions_disassemble/Kappa.s
hexdump -vC champions_disassemble/Kappa.cor > original_after_disassemble
./resources/vm_champs/asm champions/Kappa.s
hexdump -vC champions/Kappa.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "katchup.s"
./asm champions/katchup.s
hexdump -vC champions/katchup.cor > my_file
./resources/vm_champs/asm champions_disassemble/katchup.s
./asm champions_disassemble/katchup.cor
./resources/vm_champs/asm champions_disassemble/katchup.s
hexdump -vC champions_disassemble/katchup.cor > original_after_disassemble
./resources/vm_champs/asm champions/katchup.s
hexdump -vC champions/katchup.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "Kitty_Miaou.s"
./asm champions/Kitty_Miaou.s
hexdump -vC champions/Kitty_Miaou.cor > my_file
./resources/vm_champs/asm champions_disassemble/Kitty_Miaou.s
./asm champions_disassemble/Kitty_Miaou.cor
./resources/vm_champs/asm champions_disassemble/Kitty_Miaou.s
hexdump -vC champions_disassemble/Kitty_Miaou.cor > original_after_disassemble
./resources/vm_champs/asm champions/Kitty_Miaou.s
hexdump -vC champions/Kitty_Miaou.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "Kittystrophic.s"
./asm champions/Kittystrophic.s
hexdump -vC champions/Kittystrophic.cor > my_file
./resources/vm_champs/asm champions_disassemble/Kittystrophic.s
./asm champions_disassemble/Kittystrophic.cor
./resources/vm_champs/asm champions_disassemble/Kittystrophic.s
hexdump -vC champions_disassemble/Kittystrophic.cor > original_after_disassemble
./resources/vm_champs/asm champions/Kittystrophic.s
hexdump -vC champions/Kittystrophic.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "lapsang.s"
./asm champions/lapsang.s
hexdump -vC champions/lapsang.cor > my_file
./resources/vm_champs/asm champions_disassemble/lapsang.s
./asm champions_disassemble/lapsang.cor
./resources/vm_champs/asm champions_disassemble/lapsang.s
hexdump -vC champions_disassemble/lapsang.cor > original_after_disassemble
./resources/vm_champs/asm champions/lapsang.s
hexdump -vC champions/lapsang.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "le_pet_de_nonne.s"
./asm champions/le_pet_de_nonne.s
hexdump -vC champions/le_pet_de_nonne.cor > my_file
./resources/vm_champs/asm champions_disassemble/le_pet_de_nonne.s
./asm champions_disassemble/le_pet_de_nonne.cor
./resources/vm_champs/asm champions_disassemble/le_pet_de_nonne.s
hexdump -vC champions_disassemble/le_pet_de_nonne.cor > original_after_disassemble
./resources/vm_champs/asm champions/le_pet_de_nonne.s
hexdump -vC champions/le_pet_de_nonne.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "littlepuppy.s"
./asm champions/littlepuppy.s
hexdump -vC champions/littlepuppy.cor > my_file
./resources/vm_champs/asm champions_disassemble/littlepuppy.s
./asm champions_disassemble/littlepuppy.cor
./resources/vm_champs/asm champions_disassemble/littlepuppy.s
hexdump -vC champions_disassemble/littlepuppy.cor > original_after_disassemble
./resources/vm_champs/asm champions/littlepuppy.s
hexdump -vC champions/littlepuppy.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "live.s"
./asm champions/live.s
hexdump -vC champions/live.cor > my_file
./resources/vm_champs/asm champions_disassemble/live.s
./asm champions_disassemble/live.cor
./resources/vm_champs/asm champions_disassemble/live.s
hexdump -vC champions_disassemble/live.cor > original_after_disassemble
./resources/vm_champs/asm champions/live.s
hexdump -vC champions/live.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "loose.s"
./asm champions/loose.s
hexdump -vC champions/loose.cor > my_file
./resources/vm_champs/asm champions_disassemble/loose.s
./asm champions_disassemble/loose.cor
./resources/vm_champs/asm champions_disassemble/loose.s
hexdump -vC champions_disassemble/loose.cor > original_after_disassemble
./resources/vm_champs/asm champions/loose.s
hexdump -vC champions/loose.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "lou_forktologue.s"
./asm champions/lou_forktologue.s
hexdump -vC champions/lou_forktologue.cor > my_file
./resources/vm_champs/asm champions_disassemble/lou_forktologue.s
./asm champions_disassemble/lou_forktologue.cor
./resources/vm_champs/asm champions_disassemble/lou_forktologue.s
hexdump -vC champions_disassemble/lou_forktologue.cor > original_after_disassemble
./resources/vm_champs/asm champions/lou_forktologue.s
hexdump -vC champions/lou_forktologue.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "Machine-gun.s"
./asm champions/Machine-gun.s
hexdump -vC champions/Machine-gun.cor > my_file
./resources/vm_champs/asm champions_disassemble/Machine-gun.s
./asm champions_disassemble/Machine-gun.cor
./resources/vm_champs/asm champions_disassemble/Machine-gun.s
hexdump -vC champions_disassemble/Machine-gun.cor > original_after_disassemble
./resources/vm_champs/asm champions/Machine-gun.s
hexdump -vC champions/Machine-gun.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "mandragore.s"
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
./asm champions/mandragore.s
hexdump -vC champions/mandragore.cor > my_file
./resources/vm_champs/asm champions_disassemble/mandragore.s
./asm champions_disassemble/mandragore.cor
./resources/vm_champs/asm champions_disassemble/mandragore.s
hexdump -vC champions_disassemble/mandragore.cor > original_after_disassemble
./resources/vm_champs/asm champions/mandragore.s
hexdump -vC champions/mandragore.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "MarineKing.s"
./asm champions/MarineKing.s
hexdump -vC champions/MarineKing.cor > my_file
./resources/vm_champs/asm champions_disassemble/MarineKing.s
./asm champions_disassemble/MarineKing.cor
./resources/vm_champs/asm champions_disassemble/MarineKing.s
hexdump -vC champions_disassemble/MarineKing.cor > original_after_disassemble
./resources/vm_champs/asm champions/MarineKing.s
hexdump -vC champions/MarineKing.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "master_of_puppets.s"
./asm champions/master_of_puppets.s
hexdump -vC champions/master_of_puppets.cor > my_file
./resources/vm_champs/asm champions_disassemble/master_of_puppets.s
./asm champions_disassemble/master_of_puppets.cor
./resources/vm_champs/asm champions_disassemble/master_of_puppets.s
hexdump -vC champions_disassemble/master_of_puppets.cor > original_after_disassemble
./resources/vm_champs/asm champions/master_of_puppets.s
hexdump -vC champions/master_of_puppets.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "meowluigi.s"
./asm champions/meowluigi.s
hexdump -vC champions/meowluigi.cor > my_file
./resources/vm_champs/asm champions_disassemble/meowluigi.s
./asm champions_disassemble/meowluigi.cor
./resources/vm_champs/asm champions_disassemble/meowluigi.s
hexdump -vC champions_disassemble/meowluigi.cor > original_after_disassemble
./resources/vm_champs/asm champions/meowluigi.s
hexdump -vC champions/meowluigi.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "Misaka_Mikoto.s"
./asm champions/Misaka_Mikoto.s
hexdump -vC champions/Misaka_Mikoto.cor > my_file
./resources/vm_champs/asm champions_disassemble/Misaka_Mikoto.s
./asm champions_disassemble/Misaka_Mikoto.cor
./resources/vm_champs/asm champions_disassemble/Misaka_Mikoto.s
hexdump -vC champions_disassemble/Misaka_Mikoto.cor > original_after_disassemble
./resources/vm_champs/asm champions/Misaka_Mikoto.s
hexdump -vC champions/Misaka_Mikoto.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "mise_a_jour_windows95.s"
./asm champions/mise_a_jour_windows95.s
hexdump -vC champions/mise_a_jour_windows95.cor > my_file
./resources/vm_champs/asm champions_disassemble/mise_a_jour_windows95.s
./asm champions_disassemble/mise_a_jour_windows95.cor
./resources/vm_champs/asm champions_disassemble/mise_a_jour_windows95.s
hexdump -vC champions_disassemble/mise_a_jour_windows95.cor > original_after_disassemble
./resources/vm_champs/asm champions/mise_a_jour_windows95.s
hexdump -vC champions/mise_a_jour_windows95.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "NoIdea.s"
./asm champions/NoIdea.s
hexdump -vC champions/NoIdea.cor > my_file
./resources/vm_champs/asm champions_disassemble/NoIdea.s
./asm champions_disassemble/NoIdea.cor
./resources/vm_champs/asm champions_disassemble/NoIdea.s
hexdump -vC champions_disassemble/NoIdea.cor > original_after_disassemble
./resources/vm_champs/asm champions/NoIdea.s
hexdump -vC champions/NoIdea.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "O-Maley_Miaou.s"
./asm champions/O-Maley_Miaou.s
hexdump -vC champions/O-Maley_Miaou.cor > my_file
./resources/vm_champs/asm champions_disassemble/O-Maley_Miaou.s
./asm champions_disassemble/O-Maley_Miaou.cor
./resources/vm_champs/asm champions_disassemble/O-Maley_Miaou.s
hexdump -vC champions_disassemble/O-Maley_Miaou.cor > original_after_disassemble
./resources/vm_champs/asm champions/O-Maley_Miaou.s
hexdump -vC champions/O-Maley_Miaou.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "overwatch.s"
./asm champions/overwatch.s
hexdump -vC champions/overwatch.cor > my_file
./resources/vm_champs/asm champions_disassemble/overwatch.s
./asm champions_disassemble/overwatch.cor
./resources/vm_champs/asm champions_disassemble/overwatch.s
hexdump -vC champions_disassemble/overwatch.cor > original_after_disassemble
./resources/vm_champs/asm champions/overwatch.s
hexdump -vC champions/overwatch.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "pai_mu_tan.s"
./asm champions/pai_mu_tan.s
hexdump -vC champions/pai_mu_tan.cor > my_file
./resources/vm_champs/asm champions_disassemble/pai_mu_tan.s
./asm champions_disassemble/pai_mu_tan.cor
./resources/vm_champs/asm champions_disassemble/pai_mu_tan.s
hexdump -vC champions_disassemble/pai_mu_tan.cor > original_after_disassemble
./resources/vm_champs/asm champions/pai_mu_tan.s
hexdump -vC champions/pai_mu_tan.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "Rainbow_dash.s"
./asm champions/Rainbow_dash.s
hexdump -vC champions/Rainbow_dash.cor > my_file
./resources/vm_champs/asm champions_disassemble/Rainbow_dash.s
./asm champions_disassemble/Rainbow_dash.cor
./resources/vm_champs/asm champions_disassemble/Rainbow_dash.s
hexdump -vC champions_disassemble/Rainbow_dash.cor > original_after_disassemble
./resources/vm_champs/asm champions/Rainbow_dash.s
hexdump -vC champions/Rainbow_dash.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "run_Kitty_RUN.s"
./asm champions/run_Kitty_RUN.s
hexdump -vC champions/run_Kitty_RUN.cor > my_file
./resources/vm_champs/asm champions_disassemble/run_Kitty_RUN.s
./asm champions_disassemble/run_Kitty_RUN.cor
./resources/vm_champs/asm champions_disassemble/run_Kitty_RUN.s
hexdump -vC champions_disassemble/run_Kitty_RUN.cor > original_after_disassemble
./resources/vm_champs/asm champions/run_Kitty_RUN.s
hexdump -vC champions/run_Kitty_RUN.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "salamahenagalabadoun.s"
./asm champions/salamahenagalabadoun.s
hexdump -vC champions/salamahenagalabadoun.cor > my_file
./resources/vm_champs/asm champions_disassemble/salamahenagalabadoun.s
./asm champions_disassemble/salamahenagalabadoun.cor
./resources/vm_champs/asm champions_disassemble/salamahenagalabadoun.s
hexdump -vC champions_disassemble/salamahenagalabadoun.cor > original_after_disassemble
./resources/vm_champs/asm champions/salamahenagalabadoun.s
hexdump -vC champions/salamahenagalabadoun.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "sam_2.0.s"
./asm champions/sam_2.0.s
hexdump -vC champions/sam_2.0.cor > my_file
./resources/vm_champs/asm champions_disassemble/sam_2.0.s
./asm champions_disassemble/sam_2.0.cor
./resources/vm_champs/asm champions_disassemble/sam_2.0.s
hexdump -vC champions_disassemble/sam_2.0.cor > original_after_disassemble
./resources/vm_champs/asm champions/sam_2.0.s
hexdump -vC champions/sam_2.0.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "sencha.s"
./asm champions/sencha.s
hexdump -vC champions/sencha.cor > my_file
./resources/vm_champs/asm champions_disassemble/sencha.s
./asm champions_disassemble/sencha.cor
./resources/vm_champs/asm champions_disassemble/sencha.s
hexdump -vC champions_disassemble/sencha.cor > original_after_disassemble
./resources/vm_champs/asm champions/sencha.s
hexdump -vC champions/sencha.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "skynet.s"
./asm champions/skynet.s
hexdump -vC champions/skynet.cor > my_file
./resources/vm_champs/asm champions_disassemble/skynet.s
./asm champions_disassemble/skynet.cor
./resources/vm_champs/asm champions_disassemble/skynet.s
hexdump -vC champions_disassemble/skynet.cor > original_after_disassemble
./resources/vm_champs/asm champions/skynet.s
hexdump -vC champions/skynet.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "Stargate0_1.s"
./asm champions/Stargate0_1.s
hexdump -vC champions/Stargate0_1.cor > my_file
./resources/vm_champs/asm champions_disassemble/Stargate0_1.s
./asm champions_disassemble/Stargate0_1.cor
./resources/vm_champs/asm champions_disassemble/Stargate0_1.s
hexdump -vC champions_disassemble/Stargate0_1.cor > original_after_disassemble
./resources/vm_champs/asm champions/Stargate0_1.s
hexdump -vC champions/Stargate0_1.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "tchupka.s"
./asm champions/tchupka.s
hexdump -vC champions/tchupka.cor > my_file
./resources/vm_champs/asm champions_disassemble/tchupka.s
./asm champions_disassemble/tchupka.cor
./resources/vm_champs/asm champions_disassemble/tchupka.s
hexdump -vC champions_disassemble/tchupka.cor > original_after_disassemble
./resources/vm_champs/asm champions/tchupka.s
hexdump -vC champions/tchupka.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "terminator.s"
./asm champions/terminator.s
hexdump -vC champions/terminator.cor > my_file
./resources/vm_champs/asm champions_disassemble/terminator.s
./asm champions_disassemble/terminator.cor
./resources/vm_champs/asm champions_disassemble/terminator.s
hexdump -vC champions_disassemble/terminator.cor > original_after_disassemble
./resources/vm_champs/asm champions/terminator.s
hexdump -vC champions/terminator.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "TheHarvester.s"
./asm champions/TheHarvester.s
hexdump -vC champions/TheHarvester.cor > my_file
./resources/vm_champs/asm champions_disassemble/TheHarvester.s
./asm champions_disassemble/TheHarvester.cor
./resources/vm_champs/asm champions_disassemble/TheHarvester.s
hexdump -vC champions_disassemble/TheHarvester.cor > original_after_disassemble
./resources/vm_champs/asm champions/TheHarvester.s
hexdump -vC champions/TheHarvester.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "THUNDER.s"
./asm champions/THUNDER.s
hexdump -vC champions/THUNDER.cor > my_file
./resources/vm_champs/asm champions_disassemble/THUNDER.s
./asm champions_disassemble/THUNDER.cor
./resources/vm_champs/asm champions_disassemble/THUNDER.s
hexdump -vC champions_disassemble/THUNDER.cor > original_after_disassemble
./resources/vm_champs/asm champions/THUNDER.s
hexdump -vC champions/THUNDER.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "ultima.s"
./asm champions/ultima.s
hexdump -vC champions/ultima.cor > my_file
./resources/vm_champs/asm champions_disassemble/ultima.s
./asm champions_disassemble/ultima.cor
./resources/vm_champs/asm champions_disassemble/ultima.s
hexdump -vC champions_disassemble/ultima.cor > original_after_disassemble
./resources/vm_champs/asm champions/ultima.s
hexdump -vC champions/ultima.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "ultimate-surrender.s"
./asm champions/ultimate-surrender.s
hexdump -vC champions/ultimate-surrender.cor > my_file
./resources/vm_champs/asm champions_disassemble/ultimate-surrender.s
./asm champions_disassemble/ultimate-surrender.cor
./resources/vm_champs/asm champions_disassemble/ultimate-surrender.s
hexdump -vC champions_disassemble/ultimate-surrender.cor > original_after_disassemble
./resources/vm_champs/asm champions/ultimate-surrender.s
hexdump -vC champions/ultimate-surrender.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "Varimathras.s"
./asm champions/Varimathras.s
hexdump -vC champions/Varimathras.cor > my_file
./resources/vm_champs/asm champions_disassemble/Varimathras.s
./asm champions_disassemble/Varimathras.cor
./resources/vm_champs/asm champions_disassemble/Varimathras.s
hexdump -vC champions_disassemble/Varimathras.cor > original_after_disassemble
./resources/vm_champs/asm champions/Varimathras.s
hexdump -vC champions/Varimathras.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "Wall.s"
./asm champions/Wall.s
hexdump -vC champions/Wall.cor > my_file
./resources/vm_champs/asm champions_disassemble/Wall.s
./asm champions_disassemble/Wall.cor
./resources/vm_champs/asm champions_disassemble/Wall.s
hexdump -vC champions_disassemble/Wall.cor > original_after_disassemble
./resources/vm_champs/asm champions/Wall.s
hexdump -vC champions/Wall.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "wave.s"
./asm champions/wave.s
hexdump -vC champions/wave.cor > my_file
./resources/vm_champs/asm champions_disassemble/wave.s
./asm champions_disassemble/wave.cor
./resources/vm_champs/asm champions_disassemble/wave.s
hexdump -vC champions_disassemble/wave.cor > original_after_disassemble
./resources/vm_champs/asm champions/wave.s
hexdump -vC champions/wave.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/
echo "youforkmytralala.s"
./asm champions/youforkmytralala.s
hexdump -vC champions/youforkmytralala.cor > my_file
./resources/vm_champs/asm champions_disassemble/youforkmytralala.s
./asm champions_disassemble/youforkmytralala.cor
./resources/vm_champs/asm champions_disassemble/youforkmytralala.s
hexdump -vC champions_disassemble/youforkmytralala.cor > original_after_disassemble
./resources/vm_champs/asm champions/youforkmytralala.s
hexdump -vC champions/youforkmytralala.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    printf "${GREEN}OK - diff${EOC}\n"
else
    printf "${RED}KO - diff${EOC}\n"
fi
echo ""
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/