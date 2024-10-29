#include "game_logic.h"

static void activate (GtkApplication *app, gpointer user_data) {

  /* Construct a GtkBuilder instance and load our UI description */
  GtkBuilder *builder = gtk_builder_new ();
  gtk_builder_add_from_file (builder, "builder.ui", NULL);

  /* Connect signal handlers to the constructed widgets. */
  GObject *window = gtk_builder_get_object (builder, "window");
  gtk_window_set_application (GTK_WINDOW (window), app);

  GObject *p_lostLandLabel = gtk_builder_get_object (builder, "lostLandLabel");
  setLostLandLabel(p_lostLandLabel);

  GObject *p_messageLabel = gtk_builder_get_object (builder, "messageLabel");
  setMessageLabel(p_messageLabel);

  GObject *p_inputBox = gtk_builder_get_object (builder, "entry01");
  setInputBox(p_inputBox);

  GObject *p_playButton = gtk_builder_get_object (builder, "bouton02");
  setPlayButton(p_playButton);
  g_signal_connect_swapped (p_playButton, "clicked", G_CALLBACK (jouer), GTK_ENTRY(p_inputBox));

  GObject *p_continueButton = gtk_builder_get_object (builder, "boutonContinuer");
  setContinueButton(p_continueButton);
  g_signal_connect_swapped (p_continueButton, "clicked", G_CALLBACK (continuer), GTK_ENTRY(p_inputBox));
  
  // Chargement du fichier CSS
  const char cssPath[] = "styles.css";
  GtkCssProvider * cssProvider = gtk_css_provider_new();
  gtk_css_provider_load_from_path(cssProvider, cssPath);
  gtk_style_context_add_provider_for_display(
    gdk_display_get_default(),
    GTK_STYLE_PROVIDER(cssProvider),
    GTK_STYLE_PROVIDER_PRIORITY_USER);
  
  gtk_widget_set_visible (GTK_WIDGET (window), TRUE);

  /* Il n'y a plus besoin du builder */
  g_object_unref (builder);

  initialiserJeu();
}
