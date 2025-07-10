if [ ! -d bin/ ]; then 
    echo "Error : no bin found, please run build.sh first"
    exit -1
fi

cd bin

if [ ! -f image-displayer ]; then
    echo "Error : no exe found"
    exit -1
fi

export SDL_VIDEO_X11=0
export SDL_VIDEODRIVER=x11

./image-displayer