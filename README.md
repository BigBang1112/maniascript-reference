# ManiaScript Reference

- [**ManiaPlanet** 2019.11.19.1850](https://bigbang1112.github.io/maniascript-reference/maniaplanet)
- [**Trackmania** 2026.2.2.1751](https://bigbang1112.github.io/maniascript-reference/trackmania)
- [**Trackmania Turbo** 2016.11.07.1615](https://bigbang1112.github.io/maniascript-reference/tmturbo)
- [**ManiaPlanet 3 (OUTDATED)** 2015.06.18.1510](https://bigbang1112.github.io/maniascript-reference/maniaplanet3outdated)

Because I don't like Doxywizard and dealing with thousands of HTML files, I decided to make a ManiaScript reference generator that just requires to manually update the `doc.h` in the associated folders + the build version in the Doxyfile (`PROJECT_NUMBER`).

## Contribute with new doc.h

If there are new updates to Trackmania 2020, you can contribute by updating the `doc.h` in the associated folder and making a pull request.

For ManiaPlanet, it's no longer expected that the game will update.

## Doxygen Awesome

Official builds use the [Doxygen Awesome CSS](https://github.com/jothepro/doxygen-awesome-css) theme. The Doxygen and Doxygen Awesome CSS versions are pinned in [`.github/workflows/build-docs.yml`](.github/workflows/build-docs.yml) (`DOXYGEN_VERSION` and `DOXYGEN_AWESOME_CSS_VERSION`), so updating either one only takes a change there.

To build locally, clone the theme into the repository root at the same version (the folder is git-ignored):

```sh
git clone --depth 1 --branch v2.5.0 https://github.com/jothepro/doxygen-awesome-css
cd Trackmania && doxygen Doxyfile
```

## Plans

- Automatically update the build version in Doxyfile in some way
- Deploy to [bigbang1112.cz](https://bigbang1112.cz)
- Add some very wacky way to automatically update the `doc.h` files (probably won't happen)
