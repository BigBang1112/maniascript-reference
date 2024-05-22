# ManiaScript Reference

- [**ManiaPlanet** 2019.11.19.1850](https://bigbang1112.github.io/maniascript-reference/maniaplanet)
- [**Trackmania** 2024.4.30.1652](https://bigbang1112.github.io/maniascript-reference/trackmania)
- [**Trackmania Turbo** 2016.11.07.1615](https://bigbang1112.github.io/maniascript-reference/tmturbo)
- [**ManiaPlanet 3 (OUTDATED)** 2015.06.18.1510](https://bigbang1112.github.io/maniascript-reference/maniaplanet3outdated)

Because I don't like Doxywizard and dealing with thousands of HTML files, I decided to make a ManiaScript reference generator that just requires to manually update the `doc.h` in the associated folders + the build version in the Doxyfile (`PROJECT_NUMBER`).

## Contribute with new doc.h

If there are new updates to Trackmania 2020, you can contribute by updating the `doc.h` in the associated folder and making a pull request.

For ManiaPlanet, it's no longer expected that the game will update.

## Doxygen Awesome

The project includes the Doxygen Awesome CSS theme as submodule and is currently used for official builds.

## Plans

- Add `index.html` to the root folder to with game options to pick
- Automatically update the build version in Doxyfile in some way
- Deploy to [bigbang1112.cz](https://bigbang1112.cz)
- Add some very wacky way to automatically update the `doc.h` files (probably won't happen)
