<h1 align="center">🐬 So_Long</h1>


So_Long is a simple 2D game built using C and the MiniLibX graphical library. The goal of the game is to collect all collectibles on the map and escape through the exit while avoiding obstacles.

This project is part of the 42 School curriculum, designed to improve skills in window management, event handling, textures, and game logic.


<p align="center">
  <h1>📌 Features</h1>
</p>



✅ Basic 2D Gameplay – Move the player around and collect items

✅ MiniLibX Graphics – Uses the lightweight MiniLibX library for rendering

✅ Custom Maps – Load your own levels using .ber map files

✅ Movement Counter – Tracks the number of moves made

✅ Smooth Window Management – Supports window resizing, closing, and interaction

🎯 Bonus Features (Extra Points!)

🔥 Enemy Patrols – Avoid getting caught by moving enemies

🔥 Sprite Animation – Smooth character and object animations

🔥 On-Screen Move Counter – Display movements directly in the game instead of just in the terminal

<p align="center">
  <h1>🎮 Controls</h1>
</p>

Key	Action

W / ↑	Move Up

A / ←	Move Left

S / ↓	Move Down

D / →	Move Right

ESC	Quit the game

<p align="center">
  <h1>🛠 Installation & Usage</h1>
</p>

1️⃣ Clone the repository


bash:

git clone https://github.com/ikardi69/so_long.git

cd so_long

2️⃣ Compile the game

bash:

make

3️⃣ Run with a valid .ber map file

bash:

./so_long maps/valid/example_map.ber

for the bonus part:

Make bonus

./so_long_bonus maps/valid/bonus/example_map.ber

<p align="center">
  <h1>🗺 Map Format</h1>
</p>

Maps are .ber files containing the following characters:

Character	Meaning

0	Empty space

1	Wall

C	Collectible

E	Exit

P	Player start position

N Enemy position (Bonus part)

Example:

111111

1P00C1

1C0E11

111111


<p align="center">
  <h1>🖥 Dependencies</h1>
</p>

Ensure you have MiniLibX installed. If not, install it with:

bash:

git clone https://github.com/42Paris/minilibx-linux.git

cd minilibx-linux && make

Then, link it when compiling:


bash:

-L minilibx-linux -lmlx -lXext -lX11 -lm

<p align="center">
  <h1>📷 Screenshots:</h1>
</p>


![image](https://github.com/user-attachments/assets/fd1bf932-79f0-48b4-8208-41fc34ff221c)

Bonus!

![image](https://github.com/user-attachments/assets/1567d5fe-ea4e-46bf-be81-ab3fb946c190)

(You can't see the exit untill you take all the coins)


💡 Future Improvements

More enemy behaviors

Different map themes

Power-ups and obstacles

<p align="center">
  <h1>🏆 Credits</h1>
</p>

Created by Mouhssine Teffahi as part of the 42 School so_long project.

Special thanks to MiniLibX developers and OpenGameArt for free assets!

