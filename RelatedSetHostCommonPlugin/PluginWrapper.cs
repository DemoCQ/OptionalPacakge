using System.Collections.Generic;
using Windows.UI.Xaml.Controls;

namespace RelatedSetHostCommonPlugin
{
    public interface IPluginWrapper
    {
        IList<UserControl> Plugins { get; }
    }
}
