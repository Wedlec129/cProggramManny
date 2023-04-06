#Соколов Борух ККСО-04-21
# uvicorn main:app --reload --port 2022
from fastapi import FastAPI

class library:
    global listAuthor
    global listPoesy
    global listWord

    listAuthor=[]
    listPoesy=[]
    listWord=[]
    
    def __init__ (Self) :
        pass

    def getAllAuthors(Self):
        return set(listAuthor)

    def addAuthors(Self,nameAuthor,namePoesy,work):
        listAuthor.append(nameAuthor)
        listPoesy.append(namePoesy)
        listWord.append(work)

    def getAllPoesyForAuthor(Self,nameAuthor):
        thisIndex=[]
        miniListPoesy=[]
        for i in range(0,len(listPoesy)):
            if listAuthor[i] == nameAuthor:
                miniListPoesy.append(listPoesy[i])
                thisIndex.append(i)
                
        exitList=miniListPoesy
        exitIndex=thisIndex
        if len(exitList)==0:
            #print("ERROR: Not found author '"+ nameAuthor+"' ")
            return "404: NOT FOUND AUTHOR '"+nameAuthor+"' "
        return [exitList]

    def getWorkPoesyForAuthor(Self,nameAuthor,nameWork,nuch=0,end=0):
        thisIndex=[]
        miniListPoesy=[]
        for i in range(0,len(listPoesy)):
            if listAuthor[i] == nameAuthor:
                miniListPoesy.append(listPoesy[i])
                thisIndex.append(i)
        exitList=miniListPoesy
        exitIndex=thisIndex

        if len(exitList)==0:
            #print("ERROR: Not found author '"+ nameAuthor+"' ")
            return "ERROR: Not found author '"+ nameAuthor+"' "

        for i in range(0,len(exitList)):
            if nameWork==exitList[i]:
                exitListWord= listWord[exitIndex[i]]
                

                if nuch<0:
                    nuch=0

                if nuch>end:
                    nuch=0
                    end=0
                
                if end>len(exitListWord):
                    end=0

                if end==0:
                    end=len(exitListWord)
                    
                return exitListWord[nuch:end]

        #print("ERROR: Not found Poesy '"+ nameWork+"' in "+nameAuthor+" ")
        return "ERROR: Not found Poesy '"+ nameWork+"' in "+nameAuthor+" "
 
app=FastAPI()
homeLibrary=library()

homeLibrary.addAuthors("PUSHKIN","YouAndMe","""You are rich, I am very poor;
                                                You are a prose writer, I am a poet;
                                                You are blush, like a poppy color,
                                                I am like death, and thin and pale.
                                                With no worries,
                                                You live in a huge house;
                                                I'm in the midst of grief and trouble
                                                I spend my days on straw.
                                                Eat sweet food every day
                                                Pull the guilt free
                                                And you are often lazy
                                                To pay the necessary debt to nature;
                                                I'm from a stale piece,
                                                From raw and fresh water,
                                                A hundred fathoms from the attic
                                                I run for a known need.
                                                Surrounded by a crowd of slaves
                                                With a formidable gaze of despotism,
                                                Aphedron you are fat
                                                You wipe with a calico;
                                                I'm a sinful hole
                                                I do not indulge in children's fashion
                                                And Khvostov's harsh ode,
                                                Though I frown, but rub.

                                                                                                """)
homeLibrary.addAuthors("PUSHKIN","IlovedYouLoveStillPerhaps","""I loved you: love still, perhaps
                                                                In my soul it has not completely died out;
                                                                But don't let her worry you anymore;
                                                                I don't want to sadden you with anything.
                                                                I loved you silently, hopelessly,
                                                                Either timidity, or jealousy we languish;
                                                                I loved you so sincerely, so tenderly,
                                                                How God forbid you be loved to be different.""")
homeLibrary.addAuthors("PUSHKIN","She","""You are sad; confess what's wrong with you."
                                        - I love you, my friend! "But who captured you?"
                                        - She. - "But who is it? Is it Glidera, Chloe, Leela?”
                                        - Oh no! "To whom are you sacrificing your soul?"
                                        — Ah! her! "You are modest, my friend!
                                        But why are you so upset?
                                        And who's to blame? Husband, father, of course ... "
                                        "Not that, my friend! - "But what then!" - I'm not him.""")

homeLibrary.addAuthors("ESENIN","Youth","""Dreams and tears
                                            Flowers and dreams
                                            I give you.

                                            From a quiet caress
                                            And gentle fairy tale
                                            I'm on fire.

                                            How much flour
                                            holy sounds
                                            They give me!

                                            But by the force of grated
                                            I'll send everything to hell.
                                            Come to me.""")
homeLibrary.addAuthors("ESENIN","Autumn","""Quiet in the thicket of juniper along the cliff.
                                            Autumn - a red mare - scratches her mane.

                                            Above the river bank
                                            The blue clang of her horseshoes is heard.

                                            Schemnik-wind with a cautious step
                                            Creasing leaves on road ledges

                                            And kisses on the rowan bush
                                            Red ulcers to the invisible Christ.""")
homeLibrary.addAuthors("ESENIN","Sunrise","""Red dawn lit up
                                            In the dark blue sky
                                            The band appeared clear
                                            In its golden brilliance.

                                            The rays of the sun are high
                                            Reflected light in the sky.
                                            And scattered far
                                            From them new in response.

                                            Rays of bright gold
                                            Light up the ground all of a sudden.
                                            The skies are already blue
                                            Spread around.""")

homeLibrary.addAuthors("LERMONTOV","Sail","""White sail lonely
                                            In the fog of the blue sea! ..
                                            What is he looking for in a distant country?
                                            What did he throw in his native land? ..

                                            Waves are playing - the wind is whistling,
                                            And the mast bends and hides ...
                                            Alas! he is not looking for happiness
                                            And not from happiness runs!

                                            Under it, a stream of lighter azure,
                                            Above him is a golden ray of sunshine...
                                            And he, rebellious, asks for a storm,
                                            As if there is peace in the storms!""")
homeLibrary.addAuthors("LERMONTOV","Clouds","""Heavenly clouds, eternal wanderers!
                                                Steppe azure, pearl chain
                                                You rush as if like me, exiles
                                                From the sweet north to the south.

                                                Who is driving you: is it fate's decision?
                                                Is envy secret? is malice open?
                                                Or is crime burdening you?
                                                Or poisonous slander of friends?

                                                No, you are bored with barren fields ...
                                                Alien to you are passions and alien to suffering;
                                                Forever cold, forever free
                                                You have no homeland, you have no exile.""")
homeLibrary.addAuthors("LERMONTOV","Beggar","""At the gates of the holy monastery
                                                Begging for alms stood
                                                The poor man is withered, a little alive
                                                From hunger, thirst and suffering.

                                                He only asked for a piece of bread,
                                                And the gaze showed living torment,
                                                And someone laid a stone
                                                Into his outstretched hand.

                                                So I begged for your love
                                                With bitter tears, with longing;
                                                So my feelings are the best
                                                Deceived forever by you!""")


@app.get("/library",tags=["list authors"]) 
def library():
    """show you list authors"""
    return homeLibrary.getAllAuthors()


@app.get("/library/{autor}",tags=["list poesy"]) 
def libraryAutor(autor:str)->str:
    """show you list NAME poesy (STIXI) off autor"""
    return homeLibrary.getAllPoesyForAuthor(autor)


@app.get("/library/{autor}/{work}",tags=["list work"]) 
def libraryAutor(autor:str,work:str)->str:
    """show you WORKs FULL"""
    return homeLibrary.getWorkPoesyForAuthor(autor,work)


@app.get("/library/{autor}/{work}/{begin}/{end}",tags=["list work to SREZ"]) 
def libraryAutor(autor:str,work:str,begin:int,end:int)->str:
    """show you WORKs whitch SREZ"""
    return homeLibrary.getWorkPoesyForAuthor(autor,work,begin,end)
        