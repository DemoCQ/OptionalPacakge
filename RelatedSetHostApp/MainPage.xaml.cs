using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Text;
using System.Threading.Tasks;
using Windows.ApplicationModel;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Media.Imaging;
using Windows.UI.Xaml.Navigation;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

namespace RelatedSetHostApp
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class MainPage : Page
    {
        public MainPage()
        {
            this.InitializeComponent();
        }

        private void Check_Click(object sender, RoutedEventArgs e)
        {
            tbInfo.Text = "";
            StringBuilder sb = new StringBuilder();
            foreach (var item in Package.Current.Dependencies)
            {
                if (item.IsOptional)
                {
                    sb.AppendLine($"{item.DisplayName} : {item.InstalledPath}");
                }
            }
            tbInfo.Text = sb.Length == 0 ? "No OptionalPackages" : sb.ToString();
        }

        private async void LoadTxt_Click(object sender, RoutedEventArgs e)
        {
            StringBuilder sb = new StringBuilder();
            foreach (var item in Package.Current.Dependencies)
            {
                if (item.IsOptional)
                {
                    try
                    {
                        var textFile = await item.InstalledLocation.GetFileAsync("sample.txt");
                        var ras = await textFile.OpenAsync(Windows.Storage.FileAccessMode.Read);
                        StreamReader reader = new StreamReader(ras.AsStream());
                        sb.AppendLine($"Read file from package:{item.DisplayName}");
                        sb.AppendLine(reader.ReadLine());

                        sb.AppendLine($"Try to load image from package:{item.DisplayName}");
                        await loadImages(item);
                    }
                    catch(Exception ex)
                    {
                        sb.AppendLine(ex.Message);
                    }
                }
            }
            tbLoadTxtInfo.Text = sb.ToString();
        }

        private async Task loadImages(Package package)
        {
            var textFile = await package.InstalledLocation.GetFileAsync("image.jpg");
            BitmapImage bitmapImage = new BitmapImage();
            bitmapImage.SetSource(await textFile.OpenAsync(Windows.Storage.FileAccessMode.Read));

            Image image = new Image();
            image.Source = bitmapImage;
            panelImages.Children.Add(image);
        }

        private void LoadDll_Click(object sender, RoutedEventArgs e)
        {
            RelatedSetHostAppNativeHelper.NativeHelper helper = new RelatedSetHostAppNativeHelper.NativeHelper();
            helper.LoadDll("RelatedSetOptionalPackageCPPDll.dll");
            //helper.LoadDll("RelatedSetOptionalPackageCPP.exe");  // Do not load a exe with LoadPackagedLibrary
            helper.AddPlugins(this.panelPlugin);
        }
    }
}
