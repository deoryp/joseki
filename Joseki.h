/*

AB: Add Black: locations of Black stones to be placed on the board prior to the first move.
AW: Add White: locations of White stones to be placed on the board prior to the first move.
AN: Annotations: name of the person commenting the game.
AP: Application: application that was used to create the SGF file (e.g. CGOban2,...).
B: a move by Black at the location specified by the property value.
BR: Black Rank: rank of the Black player.
BT: Black Team: name of the Black team.
C: Comment: a comment.
CP: Copyright: copyright information. See Kifu Copyright Discussion.
DT: Date: date of the game.
EV: Event: name of the event (e.g. 58th Honinbo Title Match).
FF: File format: version of SGF specification governing this SGF file.
GM: Game: type of game represented by this SGF file. A property value of 1 refers to Go.
GN: Game Name: name of the game record.
HA: Handicap: the number of handicap stones given to Black. Placement of the handicap stones are set using the AB property.
KM: Komi: komi.
ON: Opening: information about the opening (fuseki), rarely used in any file.
OT: Overtime: overtime system.
PB: Black Name: name of the black player.
PC: Place: place where the game was played (e.g.: Tokyo).
PL: Player: color of player to start.
PW: White Name: name of the white player.
RE: Result: result, usually in the format "B+R" (Black wins by resign) or "B+3.5" (black wins by 3.5 moku).
RO: Round: round (e.g.: 5th game).
RU: Rules: ruleset (e.g.: Japanese).
SO: Source: source of the SGF file.
SZ: Size: size of the board, non square boards are supported.
TM: Time limit: time limit in seconds.
US: User: name of the person who created the SGF file.
W: a move by White at the location specified by the property value.
WR: White Rank: rank of the White player.
WT: White Team: name of the White team.


  "..." : terminal symbols
  [...] : option: occurs at most once
  {...} : repetition: any number of times, including zero
  (...) : grouping
    |   : exclusive or
 italics: parameter explained at some other place

Collection = GameTree { GameTree }
  GameTree   = "(" Sequence { GameTree } ")"
  Sequence   = Node { Node }
  Node       = ";" { Property }
  Property   = PropIdent PropValue { PropValue }
  PropIdent  = UcLetter { UcLetter }
  PropValue  = "[" CValueType "]"
  CValueType = (ValueType | Compose)
  ValueType  = (None | Number | Real | Double | Color | SimpleText |
                Text | Point  | Move | Stone)


Collection = List<GameTree>
GameTree = List<Node> + List<GameTree>


http://www.red-bean.com/sgf/proplist_ff.html

This is an alphabetical index to all properties defined in FF[1] (as in Kierulf's thesis), FF[3] (as on Martin's pages) and FF[4] (as in this spec).
Note: FF[2] was never made public. It's more or less identical to FF[1] - the only changes known (to me) are that the BS/WS values had been redefined.
ID   FF   Description     property type    property value
--  ----  --------------  ---------------  ---------------------------------
AB  1234  Add Black       setup            list of stone
AE  1234  Add Empty       setup            list of point
AN  --34  Annotation      game-info        simpletext
AP  ---4  Application     root             composed simpletext : simpletext
AR  ---4  Arrow           -                list of composed point : point
AS  ---4  Who adds stones - (LOA)          simpletext
AW  1234  Add White       setup            list of stone
B   1234  Black           move             move
BL  1234  Black time left move             real
BM  1234  Bad move        move             double
BR  1234  Black rank      game-info        simpletext
BS  123-  Black species   game-info        number
BT  --34  Black team      game-info        simpletext
C   1234  Comment         -                text
CA  ---4  Charset         root             simpletext
CH  123-  Check mark      -                double
CP  --34  Copyright       game-info        simpletext
CR  --34  Circle          -                list of point
DD  ---4  Dim points      - (inherit)      elist of point
DM  --34  Even position   -                double
DO  --34  Doubtful        move             none
DT  1234  Date            game-info        simpletext
EL  12--  Eval. comp move -                number
EV  1234  Event           game-info        simpletext
EX  12--  Expected move   -                move
FF  -234  Fileformat      root             number (range: 1-4)
FG  1234  Figure          -                none | composed number : simpletext
GB  1234  Good for Black  -                double
GC  1234  Game comment    game-info        text
GM  1234  Game            root             number (range: 1-5,7-16)
GN  1234  Game name       game-info        simpletext
GW  1234  Good for White  -                double
HA  1234  Handicap        game-info (Go)   number
HO  --34  Hotspot         -                double
ID  --3-  Game identifier game-info        simpletext
IP  ---4  Initial pos.    game-info (LOA)  simpletext
IT  --34  Interesting     move             none
IY  ---4  Invert Y-axis   game-info (LOA)  simpletext
KM  1234  Komi            game-info (Go)   real
KO  --34  Ko              move             none
L   12--  Letters         -                list of point
LB  --34  Label           -                list of composed point : simpletext
LN  --34  Line            -                list of composed point : point
LT  --3-  Lose on time    -                none
M   12--  Simple markup   -                list of point
MA  --34  Mark with X     -                list of point
MN  --34  Set move number move             number
N   1234  Nodename        -                simpletext
OB  --34  OtStones Black  move             number
OM  --3-  Moves/overtime  -                number
ON  --34  Opening         game-info        simpletext
OP  --3-  Overtime length -                real
OT  ---4  Overtime        game-info        simpletext
OV  --3-  Operator overhead -              real
OW  --34  OtStones White  move             number
PB  1234  Player Black    game-info        simpletext
PC  1234  Place           game-info        simpletext
PL  1234  Player to play  setup            color
PM  ---4  Print move mode - (inherit)      number
PW  1234  Player White    game-info        simpletext
RE  1234  Result          game-info        simpletext
RG  123-  Region          - (Go)           list of point
RO  1234  Round           game-info        simpletext
RU  --34  Rules           game-info        simpletext
SC  123-  Secure stones   -                list of point
SE  --3-  Selftest moves  -                list of point
SE  ---4  Markup          - (LOA)          point
SI  --3-  Sigma           -                double
SL  1234  Selected        -                list of point
SO  1234  Source          game-info        simpletext
SQ  ---4  Square          -                list of point
ST  ---4  Style           root             number (range: 0-3)
SU  ---4  Setup type      game-info (LOA)  simpletext
SZ  1234  Size            root             (number | composed number : number)
TB  1234  Territory Black - (Go)           elist of point
TC  --3-  Territory count - (Go)           number
TE  1234  Tesuji          move             double
TM  1234  Timelimit       game-info        real
TR  --34  Triangle        -                list of point
TW  1234  Territory White - (Go)           elist of point
UC  --34  Unclear pos     -                double
US  1234  User            game-info        simpletext
V   1234  Value (score)   -                real
VW  1234  View            - (inherit)      elist of point
W   1234  White           move             move
WL  1234  White time left move             real
WR  1234  White rank      game-info        simpletext
WS  123-  White species   game-info        number
WT  --34  White team      game-info        simpletext



2.2.1. Property Types (currently five):

move	Properties of this type concentrate on the move made, not on
	the position arrived at by this move.
	Move properties must not be mixed with setup properties within
	the same node.
	Note: it's bad style to have move properties in root nodes.
	(it isn't forbidden though)

setup	Properties of this type concentrate on the current position.
	Setup properties must not be mixed with move properties within
	a node.

root	Root properties may only appear in root nodes. Root nodes are
	the first nodes of gametrees, which are direct descendants from a
	collection (i.e. not gametrees within other gametrees).
	They define some global 'attributes' such as board-size, kind
	of game, used file format etc.

game-info
	Game-info properties provide some information about the game
	played (e.g. who, where, when, what, result, rules, etc.).
	These properties are usually stored in root nodes.
	When merging a set of games into a single gametree, game infos
	are stored at the nodes where a game first becomes distinguishable
	from all other games in the tree.

        A node containing game-info properties is called a game-info node.
        There may be only one game-info node on any path within the tree,
        i.e. if some game-info properties occur in one node there may not be
        any further game-info properties in following nodes:
        a) on the path from the root node to this node.
        b) in the subtree below this node.

-	no type. These properties have no special types and may appear
	anywhere in a collection.
Because of the strict distinction between move and setup properties nodes could also be divided into two classes: move-nodes and setup-nodes. This is important for databases, converting to/from ISHI-format and for some special applications.
*/