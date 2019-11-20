!wget --load-cookies /tmp/cookies.txt 
"https://docs.google.com/uc?export=download&confirm=
$(wget --quiet --save-cookies /tmp/cookies.txt 
--keep-session-cookies 
--no-check-certificate 
https://docs.google.com/uc?export=download&id=1SFo9h9lbB3rdXf3e4mDSeh0Vte9Om0Tk 
-O- | sed -rn 's/.*confirm=([0-9A-Za-z_]+).*/\1\n/p')&id=1SFo9h9lbB3rdXf3e4mDSeh0Vte9Om0Tk" 
-O bus_bst.csv && rm -rf /tmp/cookies.txt